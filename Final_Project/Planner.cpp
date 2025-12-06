//
// Created by jonat on 2025-10-23.
//

#include "Planner.h"

Planner::Planner(std::unique_ptr<ForecastProvider> provider) : provider(std::move(provider)){
}

std::vector<std::string> Planner::plan(double latitude, double longitude) {
    auto forecast = provider->get(latitude,longitude);
    std::vector<std::string> result;

    if (!forecast) {
        result.emplace_back(MakeString("Tyvärr kunde inga rekommendationer utfärdas "
                                       "eftersom hämtningen av data misslyckades."));
        return result;
    }


    result.reserve(rules.size());
    for (const auto& rule : rules) {
        auto message = rule->evaluate(forecast);
        if (!message.empty()) {
            result.emplace_back(std::move(message));
        }
    }

    result.emplace_back(MakeString("Daglig sammanfattning:\n"
                                "Temperatur: {:.0f} - {:.0f} °C\n"
                                "Vindhastiget: {:.0f} m/s\n"
                                "Nederbörd: {:.1f} ({:.0f}%) mm\n"
                                "UV-index: {:.0f}",
                                forecast->min_temp_c, forecast->max_temp_c,
                                forecast->max_wind_ms,
                                forecast->sum_precip_mm, forecast->max_precip_prob,
                                forecast->uv_index_max));

    return result;
}
