//
// Created by jonat on 2025-10-22.
//
/**
 * @file OpenMeteoProvider.h
 * @brief Deklaration för OpenMeteoProvider, en subklass av ForecastProvider.
 */
#ifndef WEATHER_PLANNER_OPEN_METEO_PROVIDER_H
#define WEATHER_PLANNER_OPEN_METEO_PROVIDER_H

#include "ForecastProvider.h"
#include "Utility.h"

/**
 * @class OpenMeteoProvider
 * @brief Utför sökning och hämtning av väderinformation
 * via Open-Meteos API.
 *
 * @note Ärvs av ForecastProvider och implementerar get().
 * @see ForecastProvider
 */
class OpenMeteoProvider : public ForecastProvider {
public:
    /**
     * @brief Bygger en request-URL baserat på koordinater, skickar förfrågan
     * och plockar ut väderinformation.
     * @param latitude Platsens latitud (grader).
     * @param longitude Platsens longitud (grader).
     * @return Returnerar ett std::optional<Forecast>-objekt. Innehåller en Forecast-struktur
     * om hämtningen lyckas, annars ett tomt optional-objekt.
     */
    [[nodiscard]] ForecastOpt get(const double& latitude, const double& longitude) override;
};

/**
 * @brief Hjälpfunktion som verifierar att en utplockad array är giltig och inte tom.
 * @param array JSON-objekt som fungerar som array.
 * @return true om det är en giltig och icke-tom array, false annars.
 */
bool array_verification(const JSON& array);

/**
 * @brief Hjälpfunktion som verifierar att nycklar är giltiga och existerar i JSON-objektet.
 * @param response_obj Svar från servern i form av ett JSON-objekt.
 * @param key1 Yttre JSON-nyckel.
 * @param key2 Inre JSON-nyckel.
 * @return true om båda nycklarna är giltiga och existerar, false annars.
 */
bool verification(const JSON& response_obj, const std::string& key1, const std::string& key2);

/**
 * @brief Hjälpfunktion som plockar ut väderinformation från ett JSON-objekt.
 * @param response_obj Svar från servern i form av ett JSON-objekt.
 * @param key1 Yttre JSON-nyckel.
 * @param key2 Inre JSON-nyckel.
 * @return Utplockat värde i form av decimaltal.
 */
double get_value(const JSON& response_obj, const std::string& key1, const std::string& key2);

#endif // WEATHER_PLANNER_OPEN_METEO_PROVIDER_H
