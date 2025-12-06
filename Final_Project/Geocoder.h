//
// Created by jonat on 2025-10-24.
//
/**
 * @file Geocoder.h
 * @brief Deklaration för basklassen till alla Geocoder-subklasser.
 */
#ifndef WEATHER_PLANNER_GEOCODER_H
#define WEATHER_PLANNER_GEOCODER_H
#include <vector>
#include "Location.h"

/**
 * @class Geocoder
 * @brief Basklass som fungerar som mall för subklasser
 * som implementerar sökning och hämtning av koordinater.
 *
 * Klassen definierar ett gemensamt gränssnitt för
 * olika leverantörer av platsinformation.
 * @note Ska inte instansieras direkt. Subklasser måste implementera search().
 */
class Geocoder {
public:
    /// @brief Virtuell destruktor som används av samtliga subklasser.
    virtual ~Geocoder() = default;

    /**
     * @brief Mallfunktion som används för att hämta och söka efter platsinformation.
     * @param query Söksträng.
     * @return Returnerar en vektor med Location-strukturer.
     */
    [[nodiscard]] virtual std::vector<Location> search(const std::string& query) = 0;
};

#endif // WEATHER_PLANNER_GEOCODER_H
