//
// Created by jonat on 2025-10-24.
//
/**
 * @file PresetGeocoder.h
 * @brief Deklaration för PresetGeocoder, en subklass av Geocoder.
 */
#ifndef WEATHER_PLANNER_PRESETGEOCODER_H
#define WEATHER_PLANNER_PRESETGEOCODER_H
#include <vector>
#include <string>
#include "Geocoder.h"
#include "Location.h"
#include "Utility.h"

/**
 * @class PresetGeocoder
 * @brief Utför sökning på ett antal förbestämda platser
 * för att hämta platsinformation.
 *
 * Klassen skapades under utvecklingen av applikationen
 * för att snabbt komma igång med systemuppbyggnaden.
 * Den har i nuläget ersatts av OpenMeteoGeocoder.
 *
 * Finns kvar eftersom tanken är att kunna utveckla den vidare
 * till en backup-lösning ifall en annan geokodare inte fungerar.
 *
 * @note Ärvs av Geocoder och implementerar search().
 * @see Geocoder
 * @see OpenMeteoGeocoder
 */
class PresetGeocoder : public Geocoder {
private:
    /// @brief Vektor som innehåller de förbestämda platserna.
    std::vector<Location> locations;

public:
    /// @brief Skapar en instans av objektet och lägger in platserna i vektorn.
    PresetGeocoder();

    /**
     * @brief Söker genom vektorn med platser efter matchningar.
     * @param query Söksträng.
     * @return Returnerar en vektor med Location-strukturer.
     */
    [[nodiscard]] std::vector<Location> search(const std::string& query) override;
};

/**
 * @brief Hjälpfunktion som undersöker om en matchning till sökfrasen återfinns.
 * @param location Plats från vektorn i form av Location-struktur.
 * @param query Söksträng.
 * @return true om en matchning hittas, false annars.
 */
bool contains(const Location& location, const std::string& query);

/**
 * @brief Hjälpfunktion som gör alla tecken i en sträng till gemener.
 * Hanterar även Å, Ä och Ö, vilka ändras till a respektive o.
 * @param str Sträng som ska konverteras.
 * @return Sträng bestående av gemener.
 */
std::string lowercase(const std::string& str);

#endif // WEATHER_PLANNER_PRESETGEOCODER_H
