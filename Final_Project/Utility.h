//
// Created by jonat on 2025-10-23.
//
/**
 * @file Utility.h
 * @brief Samlar gemensamma alias och hjälpfunktioner som används
 * i flera delar av applikationen.
 *
 * Filen innehåller hjälpfunktioner för formatering och utskrift,
 * samt typalias för JSON- och Forecast-objekt för att underlätta
 * kodläsbarhet och återanvändning.
 */
#ifndef WEATHER_PLANNER_UTILITY_H
#define WEATHER_PLANNER_UTILITY_H
#include <string>
#include <nlohmann/json_fwd.hpp>
#include "fmt/format.h"
#include "Forecast.h"
#include <optional>

/**
 * @brief Skapar en formaterad sträng baserad på formatsträngen och givna argument.
 *
 * En wrapper-funktion kring fmt::format som returnerar en std::string.
 * Används för att förenkla formaterad textgenerering.
 *
 * @tparam Args Typ(er) för de värden som används i formateringen.
 * @param fmt_str Formatsträngen (fmt::format_string).
 * @param args Argument som ska ersätta platshållarna i formatsträngen.
 * @return En formaterad std::string.
 */
template <class... Args>
std::string MakeString(fmt::format_string<Args...> fmt_str, Args&&... args) {
    return fmt::format(fmt_str, std::forward<Args>(args)...);
}

/**
 * @brief Skriver ut formaterad text till standardutmatningen.
 *
 * En wrapper-funktion kring fmt::print som förenklar formaterad utskrift.
 *
 * @tparam Args Typ(er) för de värden som används i formateringen.
 * @param fmt_str Formatsträngen (fmt::format_string).
 * @param args Argument som ska ersätta platshållarna i formatsträngen.
 */
template <class... Args>
void Print(fmt::format_string<Args...> fmt_str, Args&&... args) {
    fmt::print(fmt_str, std::forward<Args>(args)...);
}

/// @brief Alias för JSON-objekt från nlohmann-biblioteket.
using JSON = nlohmann::json;

/// @brief Alias för ett std::optional<Forecast>-objekt.
using ForecastOpt = std::optional<Forecast>;

#endif // WEATHER_PLANNER_UTILITY_H
