//
// Created by jonat on 2025-10-22.
//
/**
 * @file MildRule.h
 * @brief Deklaration för MildRule, en subklass av Rule.
 */
#ifndef WEATHER_PLANNER_MILDRULE_H
#define WEATHER_PLANNER_MILDRULE_H
#include "Rule.h"
#include "Utility.h"

/**
 * @class MildRule
 * @brief Regeln utvärderar väderdata inom ett tempererat intervall
 * för att ge användaren rekommendationer om klädsel och liknande.
 *
 * Klassen används som en del av väderlogiken för att identifiera milda dagar,
 * baserat på ett övre och ett nedre temperaturgränsvärde.
 * @note Ärvs av Rule och implementerar evaluate().
 * @see Rule
 */
class MildRule : public Rule {
private:
    /// @brief Övre gränsvärde för temperatur (°C).
    double upper_temp_threshold_c;
    /// @brief Nedre gränsvärde för temperatur (°C).
    double lower_temp_threshold_c;

public:
    /**
     * @brief Konstruerar ett MildRule-objekt.
     * @param upper_temp_c Övre temperaturgränsvärde i grader Celsius.
     * @param lower_temp_c Nedre temperaturgränsvärde i grader Celsius.
     */
    MildRule(double upper_temp_c, double lower_temp_c);

    /**
     * @brief Utvärderar väderdata och genererar en rekommendation.
     * @param forecast Ett std::optional<Forecast>-objekt.
     * @return Returnerar en sträng med rekommendationen.
     */
    [[nodiscard]] std::string evaluate(const ForecastOpt& forecast) override;
};

#endif // WEATHER_PLANNER_MILDRULE_H

