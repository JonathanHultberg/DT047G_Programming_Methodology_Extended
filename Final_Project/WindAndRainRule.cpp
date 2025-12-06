//
// Created by jonat on 2025-10-22.
//

#include "WindAndRainRule.h"

WindAndRainRule::WindAndRainRule(const double& wind_speed_ms, const double& precipitation_mm, const double& precip_probability)
:  wind_rule(wind_speed_ms), umbrella_rule(precipitation_mm, precip_probability){
}

std::string WindAndRainRule::evaluate(const ForecastOpt &forecast) {
    const bool is_wind = !wind_rule.evaluate(forecast).empty();
    const bool is_rain = !umbrella_rule.evaluate(forecast).empty();

    if (is_rain && is_wind) {
        return MakeString("Ta regnjacka istället för paraply – det blåser för mycket för paraply idag!"
            "\n(Vindhastighet: {:.0f} m/s | Total nederbörd: {:.2f} mm | Sannolikhet för regn: {:.0f} %)",
                          forecast->max_wind_ms, forecast->sum_precip_mm, forecast->max_precip_prob);
    }

    if (is_wind) {
        return wind_rule.evaluate(forecast);
    }

    if (is_rain) {
        return umbrella_rule.evaluate(forecast);
    }

    return {};
}
