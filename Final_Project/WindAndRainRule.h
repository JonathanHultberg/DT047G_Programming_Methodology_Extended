//
// Created by jonat on 2025-10-22.
//
/**
 * @file WindAndRainRule.h
 * @brief Deklaration för WindAndRainRule, en subklass av Rule.
 */
#ifndef WEATHER_PLANNER_WINDANDRAINRULE_H
#define WEATHER_PLANNER_WINDANDRAINRULE_H
#include <string>
#include "Rule.h"
#include "UmbrellaRule.h"
#include "WindRule.h"
#include "Utility.h"

/**
 * @class WindAndRainRule
 * @brief Regeln utvärderar väderdata med hänsyn till
 * gränsvärden gällande nederbörd och vindhastighet
 * för att avgöra vilken typ av regnskydd som bör användas.
 *
 * Klassen används som en del av väderlogiken för att bestämma
 * om regnskydd rekommenderas baserat på om det ska regna och/eller blåsa.
 *
 * @note Ärvs av Rule och implementerar evaluate().
 * @note Är en sammansättning av WindRule och UmbrellaRule.
 * @see Rule
 * @see WindRule
 * @see UmbrellaRule
 */
class WindAndRainRule : public Rule {
private:
    /// @brief WindRule-objekt för utvärdering av dagens maximala vindhastighet.
    WindRule wind_rule;
    /// @brief UmbrellaRule-objekt för utvärdering av dagens totala nederbörd och maximala nederbördssannolikhet.
    UmbrellaRule umbrella_rule;

public:
    /**
     * @brief Skapar ett WindAndRainRule-objekt.
     * @param wind_speed_ms Gränsvärde för vindhastighet i meter per sekund.
     * @param total_precip_mm Gränsvärde för total nederbörd i millimeter.
     * @param precip_probability Gränsvärde för nederbördssannolikhet i procent.
     */
    WindAndRainRule(const double& wind_speed_ms, const double& total_precip_mm, const double& precip_probability);

    /**
     * @brief Utvärderar väderdata och genererar en rekommendation.
     * @param forecast Ett std::optional<Forecast>-objekt.
     * @return Returnerar en sträng med rekommendationen.
     */
    [[nodiscard]] std::string evaluate(const ForecastOpt& forecast) override;
};

#endif // WEATHER_PLANNER_WINDANDRAINRULE_H

