//
// Created by jonat on 2025-10-22.
//

#include "OpenMeteoProvider.h"
#include <cpr/cpr.h>
#include <nlohmann/json.hpp>
#include <string>
#include "KeyTarget.h"

ForecastOpt OpenMeteoProvider::get(const double& latitude, const double& longitude) {
    Forecast forecast{};

    const std::string request_ulr =
    "https://api.open-meteo.com/v1/forecast"
    "?latitude=" + std::to_string(latitude) +
    "&longitude=" + std::to_string(longitude) +
    "&forecast_days=1"
    "&daily=precipitation_probability_max,temperature_2m_max,"
    "temperature_2m_min,uv_index_max,precipitation_sum,wind_speed_10m_max"
    "&timezone=auto";

    auto response = cpr::Get(cpr::Url{request_ulr}, cpr::Timeout{8000});

    if (response.error || response.status_code < 200 || response.status_code >= 300) {
        Print("HTTP-fel: code={} err={} msg={}\n",
                   response.status_code,
                   static_cast<int>(response.error.code),
                   response.error.message);
        return std::nullopt;
    }

    JSON response_json;
    try {
        response_json = JSON::parse(response.text);
    } catch (const std::exception& e) {
        Print("JSON-parse-fel: {}\n", e.what());
        return std::nullopt;
    }

    //Print("{}\n", response_json.dump(2)); //debugging syfte

    std::vector<KeyTarget> keys = {
        {"daily", "precipitation_probability_max", &Forecast::max_precip_prob},
        {"daily", "precipitation_sum", &Forecast::sum_precip_mm},
        {"daily", "temperature_2m_max", &Forecast::max_temp_c},
        {"daily", "temperature_2m_min", &Forecast::min_temp_c},
        {"daily", "uv_index_max", &Forecast::uv_index_max},
        {"daily", "wind_speed_10m_max", &Forecast::max_wind_ms, 1.0/3.6}
    };

    for (const auto& entry : keys) {
        if (verification(response_json, entry.object_target, entry.array_target)) {
            forecast.*(entry.member) = get_value(response_json, entry.object_target, entry.array_target) * entry.factor;
        }
    }

    return forecast;
}



bool verification(const JSON& response_obj, const std::string& key1, const std::string& key2) {
    return response_obj.contains(key1) && response_obj[key1].contains(key2) && array_verification(response_obj[key1][key2]);
}

bool array_verification(const JSON& array) {
    return array.is_array() && !array.empty();
}

double get_value(const JSON& response_obj, const std::string& key1, const std::string& key2) {
    return response_obj[key1][key2].at(0).get<double>();
}