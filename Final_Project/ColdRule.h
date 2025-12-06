//
// Created by jonat on 2025-10-22.
//
/**
 * @file ColdRule.h
 * @brief Deklaration för ColdRule, en subklass av Rule.
 */
#ifndef WEATHER_PLANNER_COLDRULE_H
#define WEATHER_PLANNER_COLDRULE_H
#include <string>
#include "Rule.h"
#include "Utility.h"

/**
 * @class ColdRule
 * @brief Regeln utvärderar väderdata under en temperatur gräns
 * för att ge användaren rekommendationer om klädsel och liknande.
 *
 * Klassen används som en del av väderlogiken för att identifiera kalla dagar,
 * baserat på ett temperaturgränsvärde.
 * @note Ärvs av Rule och implementerar evaluate().
 * @see Rule
 */
class ColdRule : public Rule {
private:
    /// @brief Gränsvärde för temperatur (°C).
    double temp_threshold_c;

public:
    /**
     * @brief Konstruerar ett ColdRule-objekt.
     * @param temp_c Temperaturgränsvärdet i grader Celsius.
     */
    explicit ColdRule(double temp_c);

    /**
     * @brief Utvärderar väderdata och genererar en rekommendation.
     * @param forecast Ett std::optional<Forecast>-objekt.
     * @return Returnerar en sträng med rekommendationen.
     */
    std::string evaluate(const ForecastOpt& forecast);
};

#endif // WEATHER_PLANNER_COLDRULE_H
