//
// Created by jonat on 2025-10-24.
//
/**
 * @file Application.h
 * @brief Deklaration för Application-klassen som styr programflödet.
 */

#ifndef WEATHER_PLANNER_APPLICATION_H
#define WEATHER_PLANNER_APPLICATION_H
#include <string>
#include <vector>
#include "Geocoder.h"
#include "Planner.h"


///@brief Pekartyp för geokodare som används av applikationen.
using GeocoderPtr = std::unique_ptr<Geocoder>;

/// @brief Pekartyp för planner som tar fram väderdata och rekommendationer.
using PlannerPtr = std::unique_ptr<Planner>;

/**
 * @class Application
 * @brief Huvudklassen som styr programmets flöde och användarinteraktion.
 *
 * Klassen ansvarar för att starta programmet, hantera användarinmatning via CLI,
 * kommunicera med underliggande komponenter (geokodning och väderprognoser)
 * samt presentera data och rekommendationer för användaren.
 *
 * Application fungerar som gränssnittet mellan användaren och systemets logik
 * och ser till att applikationen körs i rätt ordning.
 */
class Application {
private:
    /// @brief Platsens latitud.
    double latitude{};
    /// @brief Platsens longitud.
    double longitude{};
    /// @brief Platsens namn, region och land.
    std::string location_info{};

    /// @brief Geokodare för platssökning.
    GeocoderPtr geocoder;
    /// @brief Planner för uttag av väderdata och sammanställning av rekommendationer.
    PlannerPtr planner;

    /// @brief Rekommendationer framtagna av planner-objektet.
    std::vector<std::string> recommendations{};

    /// @brief Visar huvudmenyn och hanterar menyval.
    void menu();
    /// @brief Tar fram och lagrar rekommendationer via planner-objektet.
    void get_recommendation();
    /**
     * @brief Söker efter en plats via geokodaren.
     * @return true om sökningen genomfördes, false om den avbröts.
     */
    bool search_location();
    /**
     * @brief Låter användaren välja en plats ur sökresultatet.
     * @param locations Lista med kandidater från geokodning.
     * @return true om ett val gjordes, false om valet avbröts.
     */
    bool choose_location(const std::vector<Location>& locations);
    /// @brief Skriver ut rekommendationerna.
    void print_recommendation() const;

public:
    /**
     * @brief Skapar en Application och initierar nödvändiga gränsvärden/komponenter.
     */
    Application();

    /**
     * @brief Startar applikationen och kör huvudloopen.
     */
    void run();
};

/**
 * @brief Hjälpfunktion som “rensar” terminalen genom att skriva ut flera radbrytningar.
 */
void empty_term();

/**
 * @brief Funktionsobjekt som sorterar sökresultat på namn och därefter latitud.
 */
struct sort_name_lat {
    /**
     * @brief Jämför två Location-objekt.
     * @param a Första objektet.
     * @param b Andra objektet.
     * @return true om a ska komma före b, annars false.
     */
    bool operator()(const Location& a, const Location& b) const {
        if (a.name != b.name) return a.name < b.name;
        return a.latitude < b.latitude;
    }
};

#endif // WEATHER_PLANNER_APPLICATION_H
