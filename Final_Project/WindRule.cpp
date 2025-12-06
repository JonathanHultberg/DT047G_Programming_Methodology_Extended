//
// Created by jonat on 2025-10-22.
//
#include "WindRule.h"

WindRule::WindRule(double wind_speed_ms) : wind_threshold_ms(wind_speed_ms) {
}

std::string WindRule::evaluate(const ForecastOpt &forecast) {
    if (forecast->max_wind_ms >= wind_threshold_ms) {
        return MakeString("Ta på en vindjacka – det väntas kraftig vindar under dagen."
            "\n(Vindhastighet: {:.0f} m/s)",
            forecast->max_wind_ms);
    }
    return {};
}
