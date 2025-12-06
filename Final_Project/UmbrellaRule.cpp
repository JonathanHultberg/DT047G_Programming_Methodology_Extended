//
// Created by jonat on 2025-10-22.
//

#include "UmbrellaRule.h"

UmbrellaRule::UmbrellaRule(const double& precipitation, const double& precip_probability)
: precip_threshold_mm(precipitation), probability_threshold(precip_probability) {
}

std::string UmbrellaRule::evaluate(const ForecastOpt &forecast) {
    if (forecast->sum_precip_mm >= precip_threshold_mm && forecast->max_precip_prob >= probability_threshold) {
        return MakeString("Ta med paraply – stor risk för regn idag!"
            "\n(Total nederbörd: {:.1f} mm | Sannolikhet för regn: {:.0f} %)",
            forecast->sum_precip_mm, forecast->max_precip_prob);
    }
    if (forecast->sum_precip_mm >= precip_threshold_mm) {
        return MakeString("Ett paraply kan vara bra att ha med – sannolikheten är låg, men om det regnar kommer det mycket."
            "\n(Total nederbörd: {:.1f} mm | Sannolikhet för regn: {:.0f} %)",
            forecast->sum_precip_mm, forecast->max_precip_prob);
    }
    if (forecast->max_precip_prob >= probability_threshold) {
        return MakeString("Paraply är inte nödvändigt – sannolikheten är hög, men det kommer inte bli mycket regn."
            "\n(Total nederbörd: {:.1f} mm | Sannolikhet för regn: {:.0f} %)",
            forecast->sum_precip_mm, forecast->max_precip_prob);
    }
    return{};
}