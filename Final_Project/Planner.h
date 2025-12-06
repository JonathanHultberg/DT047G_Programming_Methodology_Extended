//
// Created by jonat on 2025-10-23.
//
/**
 * @file Planner.h
 * @brief Deklaration för Planner-klassen som utför
 * hämtning och sammanställning av rekommendationer.
 */
#ifndef WEATHER_PLANNER_PLANNER_H
#define WEATHER_PLANNER_PLANNER_H
#include <memory>
#include <vector>
#include "ForecastProvider.h"
#include "Rule.h"


/// @brief Vektor med pekare till Rule-subklasser.
using Rules = std::vector<std::unique_ptr<Rule>>;

/// @brief Pekare till ForecastProvider för hämtning av väderinformation.
using ForecastProviderPtr = std::unique_ptr<ForecastProvider>;

/**
 * @class Planner
 * @brief Hämtar och utvärderar väderinformation för att generera rekommendationer.
 *
 * Klassen har i uppgift att utvärdera väderinformation som hämtats från en
 * ForecastProvider med hjälp av definierade regler, och sammanställa dessa
 * till rekommendationer för användaren.
 */
class Planner {
private:
    /// @brief Leverantör för hämtning av väderinformation.
    ForecastProviderPtr provider;
    /// @brief Regler som används för utvärdering.
    Rules rules;

public:
    /**
     * @brief Skapar en Planner och initierar nödvändiga värden.
     * @param provider Pekare till leverantören av väderinformation.
     */
    explicit Planner(std::unique_ptr<ForecastProvider> provider);

    /**
     * @brief Lägger till en ny regel i samlingen.
     *
     * Skapar ett unikt pekarobjekt av den angivna regeltypen och
     * för vidare konstruktorargument till dess konstruktor.
     * Lagrar sedan regeln i vektorn över regler.
     *
     * @tparam TRule Typen av regeln som ska läggas till. Måste vara en subklass av Rule.
     * @tparam Args Typ(er) för argument som skickas vidare till TRule:s konstruktor.
     * @param args Argument som skickas vidare till konstruktorn för TRule.
     */
    template<class TRule, class... Args>
    void add_rule(Args&&... args) {
        auto pointer = std::make_unique<TRule>(std::forward<Args>(args)...);
        rules.emplace_back(std::move(pointer));
    }

    /**
     * @brief Hämtar väderinformation utifrån koordinater, utvärderar informationen
     * och sammanställer rekommendationer för användaren.
     * @param latitude Platsens latitud (grader).
     * @param longitude Platsens longitud (grader).
     * @return Vektor med sammanställda rekommendationer i form av strängar.
     */
    [[nodiscard]] std::vector<std::string> plan(double latitude, double longitude);
};

#endif // WEATHER_PLANNER_PLANNER_H

