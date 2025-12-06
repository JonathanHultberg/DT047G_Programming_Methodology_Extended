//
// Created by jonat on 2025-10-22.
//
/**
 * @file Forecast.h
 * @brief Deklaration för Forecast-strukturen.
 */
#ifndef WEATHER_PLANNER_FORECAST_H
#define WEATHER_PLANNER_FORECAST_H

/**
 * @struct Forecast
 * @brief Datatyp som används för att lagra väderinformation.
 *
 * Innehåller olika dagliga värden såsom temperatur, vindhastighet,
 * nederbörd, sannolikhet för regn och UV-index.
 */
struct Forecast {
    /// @brief Högsta dagliga temperaturen (°C).
    double max_temp_c{};
    /// @brief Lägsta dagliga temperaturen (°C).
    double min_temp_c{};
    /// @brief Högsta dagliga vindhastigheten (m/s).
    double max_wind_ms{};
    /// @brief Total nederbörd under dagen (mm).
    double sum_precip_mm{};
    /// @brief Högsta sannolikhet för nederbörd under dagen (%).
    double max_precip_prob{};
    /// @brief Högsta UV-index under dagen.
    double uv_index_max{};
};

#endif // WEATHER_PLANNER_FORECAST_H
