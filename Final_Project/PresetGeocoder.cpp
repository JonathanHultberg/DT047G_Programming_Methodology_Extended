//
// Created by jonat on 2025-10-24.
//

#include "PresetGeocoder.h"
#include "cctype"

PresetGeocoder::PresetGeocoder() {
    locations = {
        {"Sundsvall", "Västernorrland", "SWE", 62.39129, 17.3063},
        {"Stockholm", "Stockholm", "SWE", 59.33258, 18.0649},
        {"Göteborg", "Västra Götaland", "SWE", 57.70716, 11.96679},
        {"Uppsala", "Uppsala", "SWE", 59.85882, 17.63889},
        {"Trollhättan", "Västra Götaland", "SWE", 58.28365, 12.28864},
        {"Malmö", "Skåne", "SWE", 55.60587, 13.00073},
        {"Gävle", "Gävleborg", "SWE", 60.67452, 17.14174},
        {"Umeå", "Västerbotten", "SWE", 65.58415, 22.15465},
        {"Luleå", "Norrbotten", "SWE", 65.58415, 22.15465}
    };
}

std::vector<Location> PresetGeocoder::search(const std::string &query) {
    std::vector<Location> result;

    for (const auto& location: locations) {
        if (contains(location, query)) {
            result.push_back(location);
        }
    }
    if (result.empty()) {
        Print("Tyvärr hittades inga matchningar.\n\n");
    }
    return result;
}

bool contains(const Location& location, const std::string& query) {
    std::string location_name = lowercase(location.name);
    std::string location_region = lowercase(location.region);
    std::string location_country = lowercase(location.country);
    std::string query_lower = lowercase(query);

    return location_name.find(query_lower) != std::string::npos
    || location_region.find(query_lower) != std::string::npos
    || location_country.find(query_lower) != std::string::npos;
}


std::string lowercase(const std::string& str) {
    std::string result{};

    for (std::size_t i = 0; i < str.length(); i++) {
        unsigned char byte = static_cast<unsigned char>(str[i]);

        if (byte < 0x80) {
            result.push_back(std::tolower(static_cast<char>(byte)));
        } else if (byte == 0xC3 && i + 1 < str.length()) {
            unsigned char second_byte = static_cast<unsigned char>(str[i + 1]);

            if (second_byte == 0x85 || second_byte == 0xA5) {
                result.push_back('a');
            } else if (second_byte == 0x84 || second_byte == 0xA4) {
                result.push_back('a');
            } else if (second_byte == 0x96 || second_byte == 0xB6) {
                result.push_back('o');
            } else {
                result.push_back(static_cast<char>(byte));
                result.push_back(static_cast<char>(second_byte));
            }
            ++i;
        }
        else {
            result.push_back(static_cast<char>(byte));
        }
    }
    return result;
}
