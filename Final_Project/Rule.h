//
// Created by jonat on 2025-10-22.
//
/**
 * @file Rule.h
 * @brief Deklaration för basklassen till alla Rule-subklasser.
 */
#ifndef WEATHER_PLANNER_RULE_H
#define WEATHER_PLANNER_RULE_H
#include <string>
#include "Utility.h"

/**
 * @class Rule
 * @brief Basklass som fungerar som mall för subklasser
 * som implementerar utvärdering av väderinformation samt
 * utfärdar rekommendationer baserade på utvärderingen.
 *
 * Klassen definierar ett gemensamt gränssnitt för
 * olika regler som används för att utvärdera väderdata
 * och generera rekommendationer.
 *
 * @note Är abstrakt och ska inte instansieras direkt.
 */
class Rule {
public:
    /// @brief Virtuell destruktor som används av samtliga subklasser.
    virtual ~Rule() = default;

    /**
     * @brief Mallfunktion för utvärdering av väderinformation och
     * utfärdande av rekommendationer.
     * @param forecast Ett std::optional<Forecast>-objekt.
     * @return Returnerar en sträng med rekommendationen.
     */
    [[nodiscard]] virtual std::string evaluate(const ForecastOpt& forecast) = 0;
};

#endif // WEATHER_PLANNER_RULE_H
