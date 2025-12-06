//
// Created by jonat on 2025-10-22.
//

#include "MildRule.h"


MildRule::MildRule(double upper_temp_c, double lower_temp_c)
: upper_temp_threshold_c(upper_temp_c), lower_temp_threshold_c(lower_temp_c){
}

std::string MildRule::evaluate(const ForecastOpt& forecast) {
    if (forecast->max_temp_c <= upper_temp_threshold_c && forecast->max_temp_c >= lower_temp_threshold_c) {
        return MakeString("Använd lager på lager – temperaturen växlar mellan varmt och kallt."
                              "\n(Temperatur: {:.0f} – {:.0f} °C)",
                              forecast->min_temp_c, forecast->max_temp_c);
    }
    if (forecast->min_temp_c < lower_temp_threshold_c) {
        return MakeString("Använd lager på lager – se till att ha något varmt, det kan bli kallt idag."
            "\n(Temperatur: {:.0f} – {:.0f} °C)",
            forecast->min_temp_c, forecast->max_temp_c);
    }
    return{};
}
