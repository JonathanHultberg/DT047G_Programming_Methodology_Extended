//
// Created by jonat on 2025-10-24.
//
/**
 * @file Location.h
 * @brief Deklaration för Location-strukturen.
 */
#ifndef WEATHER_PLANNER_LOCATION_H
#define WEATHER_PLANNER_LOCATION_H
#include <string>

/**
 * @struct Location
 * @brief Datatyp som används för att lagra platsinformation.
 *
 * Används vid sökning och hämtning av platsdata via Geocoder-klasser.
 * Innehåller platsens namn, region, land samt dess latitud och longitud.
 */
struct Location {
    /// @brief Platsens namn.
    std::string name;
    /// @brief Platsens region.
    std::string region;
    /// @brief Platsens land.
    std::string country;
    /// @brief Platsens latitud.
    double latitude;
    /// @brief Platsens longitud.
    double longitude;
};

#endif // WEATHER_PLANNER_LOCATION_H
