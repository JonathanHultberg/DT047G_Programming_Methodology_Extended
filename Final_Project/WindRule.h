//
// Created by jonat on 2025-10-22.
//
/**
 * @file WindRule.h
 * @brief Deklaration för WindRule, en subklass av Rule.
 */
#ifndef WEATHER_PLANNER_WINDRULE_H
#define WEATHER_PLANNER_WINDRULE_H
#include <string>
#include "Rule.h"
#include "Utility.h"

/**
 * @class WindRule
 * @brief Regeln utvärderar om väderdata överstiger ett gränsvärde
 * för vindhastighet för att ge användaren en rekommendation om klädsel.
 *
 * Klassen används som en del av väderlogiken för att identifiera blåsiga dagar,
 * baserat på ett vindhastighetsgränsvärde.
 *
 * @note Ärvs av Rule och implementerar evaluate().
 * @see Rule
 */
class WindRule : public Rule {
private:
    /// @brief Gränsvärde för vindhastighet (m/s).
    double wind_threshold_ms;

public:
    /**
     * @brief Skapar ett WindRule-objekt.
     * @param wind_speed_ms Gränsvärde för vindhastighet i meter per sekund.
     */
    explicit WindRule(double wind_speed_ms);

    /**
     * @brief Utvärderar väderdata och genererar en rekommendation.
     * @param forecast Ett std::optional<Forecast>-objekt.
     * @return Returnerar en sträng med rekommendationen.
     */
    [[nodiscard]] std::string evaluate(const ForecastOpt& forecast) override;
};

#endif // WEATHER_PLANNER_WINDRULE_H
