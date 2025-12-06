//
// Created by jonat on 2025-10-25.
//
/**
 * @file OpenMeteoGeocoder.h
 * @brief Deklaration för OpenMeteoGeocoder, en subklass av Geocoder.
 */
#ifndef WEATHER_PLANNER_OPENMETEOGEOCODER_H
#define WEATHER_PLANNER_OPENMETEOGEOCODER_H

#include "Geocoder.h"
#include "Utility.h"

/**
 * @class OpenMeteoGeocoder
 * @brief Utför sökning och hämtning av platsinformation
 * via Open-Meteos API.
 *
 * @note Ärvs av Geocoder och implementerar search().
 * @see Geocoder
 */
class OpenMeteoGeocoder : public Geocoder {
public:
    /**
     * @brief Bygger en request-URL baserat på söksträngen, skickar förfrågan
     * och plockar ut platsinformation.
     * @param query Söksträng.
     * @return Returnerar en vektor med Location-strukturer.
     */
    [[nodiscard]] std::vector<Location> search(const std::string& query) override;
};

/**
 * @brief Hjälpfunktion som plockar ut platsinformation från ett JSON-objekt.
 * @param response_obj Svar från servern i form av ett JSON-objekt.
 * @return Location-struktur med utplockad platsinformation.
 */
Location extract(const JSON& response_obj);

#endif // WEATHER_PLANNER_OPENMETEOGEOCODER_H
