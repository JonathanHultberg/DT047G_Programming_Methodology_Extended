//
// Created by jonat on 2025-10-24.
//

#include "UvIndexRule.h"

UvIndexRule::UvIndexRule(const double& high_uv_index, const double& low_uv_index)
: uv_index_high(high_uv_index), uv_index_low(low_uv_index) {
}

std::string UvIndexRule::evaluate(const ForecastOpt &forecast) {
    if (forecast->uv_index_max < uv_index_low) {
        return MakeString("Du kan lugnt vara ute idag – UV-indexet är lågt. Passa på att fylla på med lite D-vitamin!"
            "\n(UV-index: {:.0f})",
                forecast->uv_index_max);
    }
    if (forecast->uv_index_max >= uv_index_low && forecast->uv_index_max < uv_index_high) {
        return MakeString("Sök skugga mitt på dagen och använd solskydd – ha gärna hatt och tröja på dig. UV-indexet är medelhögt till högt."
            "\n(UV-index: {:.0f})",
                forecast->uv_index_max);
    }
    if (forecast->uv_index_max >= uv_index_high) {
        return MakeString("Undvik att vara utomhus mitt på dagen – sök skugga, och använd hatt och tröja. UV-indexet är högt till extremt."
            "\n(UV-index: {:.0f})",
                forecast->uv_index_max);
    }

    return {};
}
