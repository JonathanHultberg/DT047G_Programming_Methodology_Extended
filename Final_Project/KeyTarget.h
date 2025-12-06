//
// Created by jonat on 2025-10-24.
//
/**
 * @file KeyTarget.h
 * @brief Deklaration för KeyTarget-strukturen.
 */
#ifndef WEATHER_PLANNER_KEYTARGET_H
#define WEATHER_PLANNER_KEYTARGET_H
#include "Forecast.h"
#include <string>

/**
 * @struct KeyTarget
 * @brief Datatyp som används vid verifiering och uttag av data
 * från ett JSON-objekt i samband med hämtning av väderinformation
 * via OpenMeteoProvider.
 *
 * Strukturen innehåller information om vilka nycklar som ska läsas från
 * JSON-objektet, pekare till medlemmar i Forecast-strukturen samt en
 * faktor för eventuell enhetsomvandling.
 */
struct KeyTarget {
    /// @brief Yttre JSON-nyckel.
    std::string object_target{};
    /// @brief Inre JSON-nyckel.
    std::string array_target{};
    /// @brief Pekare till medlem i Forecast-strukturen som värdet ska tilldelas.
    double Forecast::* member;
    /// @brief Faktor som används vid eventuell enhetsomvandling.
    double factor = 1.0;
};

#endif // WEATHER_PLANNER_KEYTARGET_H
