//
// Created by jonat on 2025-10-22.
//
/**
 * @file UmbrellaRule.h
 * @brief Deklaration för UmbrellaRule, en subklass av Rule.
 */
#ifndef WEATHER_PLANNER_UMBRELLARULE_H
#define WEATHER_PLANNER_UMBRELLARULE_H
#include <string>
#include "Rule.h"
#include "Utility.h"

/**
 * @class UmbrellaRule
 * @brief Regeln utvärderar väderdata med hänsyn till
 * gränsvärden gällande nederbörd och dess sannolikhet,
 * för att ge rekommendation om paraply behövs eller ej.
 *
 * Klassen används som en del av väderlogiken för att avgöra
 * om regnskydd rekommenderas baserat på mängden nederbörd
 * och sannolikheten för regn.
 * @note Ärvs av Rule och implementerar evaluate().
 * @see Rule
 */
class UmbrellaRule : public Rule {
private:
    /// @brief Gränsvärde för den totala nederbörden under en dag (mm).
    double precip_threshold_mm;
    /// @brief Gränsvärde för nederbördssannolikheten (%).
    double probability_threshold;

public:
    /**
     * @brief Konstruerar ett UmbrellaRule-objekt.
     * @param total_precip_mm Gränsvärde för total nederbörd i millimeter.
     * @param precip_probability Gränsvärde för nederbördssannolikhet i procent.
     */
    explicit UmbrellaRule(const double& total_precip_mm, const double& precip_probability);

    /**
     * @brief Utvärderar väderdata och genererar en rekommendation.
     * @param forecast Ett std::optional<Forecast>-objekt.
     * @return Returnerar en sträng med rekommendationen.
     */
    [[nodiscard]] std::string evaluate(const ForecastOpt& forecast) override;
};

#endif // WEATHER_PLANNER_UMBRELLARULE_H
