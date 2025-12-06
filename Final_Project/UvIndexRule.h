//
// Created by jonat on 2025-10-24.
//
/**
 * @file UvIndexRule.h
 * @brief Deklaration för UvIndexRule, en subklass av Rule.
 */
#ifndef WEATHER_PLANNER_UVINDEXRULE_H
#define WEATHER_PLANNER_UVINDEXRULE_H
#include <string>
#include "Rule.h"
#include "Utility.h"

/**
 * @class UvIndexRule
 * @brief Regeln utvärderar väderdata baserat på om UV-indexet
 * ligger under, inom eller över ett specificerat intervall.
 *
 * Klassen används som en del av väderlogiken för att rekommendera
 * vilken nivå av solskydd som krävs beroende på vilket intervall
 * UV-indexet ligger inom.
 *
 * @note Ärvs av Rule och implementerar evaluate().
 * @see Rule
 */
class UvIndexRule : public Rule {
private:
    /// @brief Gränsvärde mellan medel och högt UV-index.
    double uv_index_high{};
    /// @brief Gränsvärde mellan lågt och medel UV-index.
    double uv_index_low{};

public:
    /**
     * @brief Konstruerar ett UvIndexRule-objekt.
     * @param high_uv_index Gränsvärde för övergången mellan medel och högt UV-index.
     * @param low_uv_index Gränsvärde för övergången mellan lågt och medel UV-index.
     */
    UvIndexRule(const double& high_uv_index, const double& low_uv_index);

    /**
     * @brief Utvärderar väderdata och genererar en rekommendation.
     * @param forecast Ett std::optional<Forecast>-objekt.
     * @return Returnerar en sträng med rekommendationen.
     */
    [[nodiscard]] std::string evaluate(const ForecastOpt& forecast) override;
};

#endif // WEATHER_PLANNER_UVINDEXRULE_H
