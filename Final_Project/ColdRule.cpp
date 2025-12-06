//
// Created by jonat on 2025-10-22.
//

#include "ColdRule.h"

ColdRule::ColdRule(double temp_c) : temp_threshold_c(temp_c) {
}

std::string ColdRule::evaluate(const ForecastOpt &forecast) {
    if (forecast->max_temp_c <= temp_threshold_c) {
        return MakeString("Klä dig varmt – det kommer vara kyligt idag."
                          "\n(Temperatur: {:.0f} – {:.0f} °C)",
                forecast->min_temp_c, forecast->max_temp_c);;
    }
    return{};
}
