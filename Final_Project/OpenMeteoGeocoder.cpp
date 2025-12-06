//
// Created by jonat on 2025-10-25.
//

#include "OpenMeteoGeocoder.h"

#include <iostream>
#include <cpr/api.h>
#include <nlohmann/json.hpp>
#include <string>

std::vector<Location> OpenMeteoGeocoder::search(const std::string& query) {
    std::vector<Location> search_result{};

    auto response = cpr::Get(
        cpr::Url{"https://geocoding-api.open-meteo.com/v1/search"},
        cpr::Parameters{
            {"name", query},
            {"language", "sv"},
            {"count", "15"},
            {"format", "json"}
        }
    );

    if (response.error || response.status_code < 200 || response.status_code >= 300) {
        Print("HTTP-fel: code={} err={} msg={}\n\n",
                   response.status_code,
                   static_cast<int>(response.error.code),
                   response.error.message);
    }

    JSON response_json;
    try {
        response_json = JSON::parse(response.text);

    } catch (const std::exception& e) {
        Print("JSON-parse-fel: {}\n\n", e.what());
    }

    if (!response_json.contains("results")) {
        Print("Tyvärr hittades inga matchningar.\n\n");
        return search_result;
    }

    search_result.reserve(response_json["results"].size());
    for (size_t i = 0; i < response_json["results"].size(); ++i) {
        const auto& result = response_json["results"][i];
        search_result.emplace_back(extract(result));

    }

    return search_result;
}

Location extract(const JSON& response_obj) {
    return {response_obj.value("name", ""), response_obj.value("admin1", ""),
            response_obj.value("country_code", ""), response_obj.value("latitude", 0.0),
            response_obj.value("longitude", 0.0)};
}