//
// Created by jonat on 2025-10-22.
//
/**
 * @file ForecastProvider.h
 * @brief Deklaration för basklassen till alla Provider-subklasser.
 */

#ifndef WEATHER_PLANNER_FORECASTPROVIDER_H
#define WEATHER_PLANNER_FORECASTPROVIDER_H
#include <optional>
#include "Utility.h"

/**
 * @class ForecastProvider
 * @brief Basklass som fungerar som mall för subklasser
 * som implementerar hämtning av väderdata.
 *
 * Klassen definierar ett gemensamt gränssnitt för
 * olika leverantörer av väderinformation.
 */
class ForecastProvider {
public:
    /// @brief Virtuell destruktor som används av samtliga subklasser.
    virtual ~ForecastProvider() = default;

    /**
     * @brief Mallfunktion som används för att hämta väderinformation.
     * @param latitude Platsens latitud (grader).
     * @param longitude Platsens longitud (grader).
     * @return Returnerar ett std::optional<Forecast>-objekt. Innehåller en Forecast-struktur
     * om hämtningen lyckas, annars ett tomt optional-objekt.
     */
    [[nodiscard]] virtual ForecastOpt get(const double& latitude, const double& longitude) = 0;
};

#endif // WEATHER_PLANNER_FORECASTPROVIDER_H
