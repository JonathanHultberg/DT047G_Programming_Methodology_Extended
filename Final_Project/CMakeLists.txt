cmake_minimum_required(VERSION 3.25)
project(weather_planner LANGUAGES CXX)

# Standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Bygg statiskt (inga DLL:er)
set(BUILD_SHARED_LIBS OFF)

# Låt oss tvinga underprojektens options
if(POLICY CMP0077)
    cmake_policy(SET CMP0077 NEW)
endif()

# curl/TLS – bara relevant på Windows
if (WIN32)
    # curl via SChannel (Windows inbyggd TLS) för att slippa OpenSSL-DLL
    set(CURL_USE_SCHANNEL ON CACHE BOOL "" FORCE)
    set(CURL_ENABLE_SSL   ON CACHE BOOL "" FORCE)
    set(CURL_ZLIB         OFF CACHE BOOL "" FORCE)
    set(CURL_BROTLI       OFF CACHE BOOL "" FORCE)
    set(CURL_ZSTD         OFF CACHE BOOL "" FORCE)
endif()

# cpr-konfig
set(CPR_USE_SYSTEM_CURL OFF CACHE BOOL "" FORCE)
set(CPR_BUILD_TESTS     OFF CACHE BOOL "" FORCE)

# (valfritt) statisk MSVC runtime
if (MSVC)
    set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")
endif()

include(FetchContent)

# fmt
FetchContent_Declare(fmt
        GIT_REPOSITORY https://github.com/fmtlib/fmt.git
        GIT_TAG 11.0.2)
FetchContent_MakeAvailable(fmt)

# nlohmann::json
FetchContent_Declare(json
        GIT_REPOSITORY https://github.com/nlohmann/json.git
        GIT_TAG v3.11.3)
FetchContent_MakeAvailable(json)

# cpr (HTTP)
FetchContent_Declare(cpr
        GIT_REPOSITORY https://github.com/libcpr/cpr.git
        GIT_TAG 1.10.5)
FetchContent_MakeAvailable(cpr)

add_executable(weather_planner
        main.cpp
        forecast.h
        ForecastProvider.h
        OpenMeteoProvider.cpp
        OpenMeteoProvider.h
        Rule.h
        UmbrellaRule.cpp
        UmbrellaRule.h
        ColdRule.cpp
        ColdRule.h
        WindRule.cpp
        WindRule.h
        MildRule.cpp
        MildRule.h
        WindAndRainRule.cpp
        WindAndRainRule.h
        Planner.cpp
        Planner.h
        Utility.h
        KeyTarget.h
        UvIndexRule.cpp
        UvIndexRule.h
        Application.cpp
        Application.h
        Location.h
        Geocoder.h
        PresetGeocoder.h
        PresetGeocoder.cpp
        OpenMeteoGeocoder.cpp
        OpenMeteoGeocoder.h
)

target_link_libraries(weather_planner
        PRIVATE
        cpr::cpr
        nlohmann_json::nlohmann_json
        fmt::fmt
)
