# Weather Planner: Clothing Recommendations from the Forecast (C++)

A command-line application that looks up today's weather for any place and tells you **what to wear and bring**: an umbrella, a rain jacket, warm layers or sun protection. It was built as the final project in *DT047G Programming Methodology* at Mid Sweden University, with a focus on **object-oriented design**, and received grade **A**.

> The program's interface is in Swedish.

## How it works

1. **Search for a place.** The app calls the Open-Meteo Geocoding API and shows the matches, sorted by name.
2. **Fetch the forecast.** It gets today's max/min temperature, precipitation, chance of rain, wind speed and UV index from the Open-Meteo Forecast API.
3. **Evaluate rules.** A `Planner` runs the forecast through a set of interchangeable `Rule` objects. Each rule returns a recommendation or nothing.
4. **Present the result.** All recommendations are printed together with the values that triggered them.

### Example output

The values below are illustrative.

```
Dagens recommendationer för Sundsvall, Västernorrland, Sverige :

Ta regnjacka istället för paraply – det blåser för mycket för paraply idag!
(Vindhastighet: 9 m/s | Total nederbörd: 6.20 mm | Sannolikhet för regn: 80 %)

Använd lager på lager – temperaturen växlar mellan varmt och kallt.
(Temperatur: 4 – 9 °C)

Du kan lugnt vara ute idag – UV-indexet är lågt. Passa på att fylla på med lite D-vitamin!
(UV-index: 1)
```

## Design

The project is built around **abstract interfaces** and **dependency injection**. Data sources and rules can be swapped or extended without changing the rest of the code.

```
Application
 ├── Geocoder (interface)        ← OpenMeteoGeocoder, PresetGeocoder
 └── Planner
      ├── ForecastProvider (interface) ← OpenMeteoProvider
      └── std::vector<std::unique_ptr<Rule>>
            ├── WindAndRainRule   (combines WindRule + UmbrellaRule)
            ├── ColdRule
            ├── MildRule
            └── UvIndexRule
```

- **Strategy pattern / polymorphism.** Every rule inherits from the abstract `Rule` class and implements `evaluate()`.
- **Composition.** `WindAndRainRule` reuses `WindRule` and `UmbrellaRule` and recommends a rain jacket instead of an umbrella when it is both windy and rainy.
- **Configurable thresholds.** Rules are registered with their thresholds through a variadic template:
  ```cpp
  planner->add_rule<WindAndRainRule>(8.0, 5.0, 50.0); // m/s, mm, %
  planner->add_rule<ColdRule>(0.0);                   // °C
  planner->add_rule<MildRule>(12.0, 5.0);             // °C
  planner->add_rule<UvIndexRule>(3.0, 8.0);           // UV index
  ```
- **Swappable data source.** `PresetGeocoder` is an offline alternative to the online geocoder and works through the same interface.
- **Safe resource handling.** The code uses `std::unique_ptr` throughout, `std::optional<Forecast>` for fetches that can fail, and `[[nodiscard]]`.
- **Documentation.** The code is documented with **Doxygen**, and a `Doxyfile` is included.

## Technologies

| | |
|---|---|
| **Language** | C++20 (`std::ranges`, `std::optional`, variadic templates, perfect forwarding) |
| **Build** | CMake (≥ 3.25) with `FetchContent`, so no manual installs are needed |
| **HTTP** | [cpr](https://github.com/libcpr/cpr), a C++ wrapper around libcurl |
| **JSON** | [nlohmann/json](https://github.com/nlohmann/json) |
| **Formatting** | [{fmt}](https://github.com/fmtlib/fmt) |
| **API** | [Open-Meteo](https://open-meteo.com/) Forecast and Geocoding (free, no API key) |
| **Docs** | Doxygen |

## Build and run

CMake downloads all dependencies automatically on the first build.

```bash
cmake -S . -B build -DCMAKE_BUILD_TYPE=Release
cmake --build build
./build/weather_planner
```

On Windows the program is built statically with SChannel for TLS, so no extra DLLs are needed.

Generate the documentation with:

```bash
doxygen Doxyfile
```

## Author

**Jonathan Hultberg**, Computer Engineering student at Mid Sweden University
