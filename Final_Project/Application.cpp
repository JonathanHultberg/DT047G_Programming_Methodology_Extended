//
// Created by jonat on 2025-10-24.
//

#include "Application.h"
#include <algorithm>
#include <iostream>
#include "ColdRule.h"
#include "MildRule.h"
#include "OpenMeteoGeocoder.h"
#include "OpenMeteoProvider.h"
#include "UvIndexRule.h"
#include "WindAndRainRule.h"

void Application::menu() {
    bool menu_running = true;
    int option = -1;

    empty_term();
    Print("Välkommen till väderplaneraren!\n\n");
    do {
        Print("Meny:\n"
              "[1] Hämta väderrekommendationer\n"
              "[0] Avsluta programmet\n"
              "Skriv in ditt val och tryck ENTER.\n\n");

        std::cout << "Input> ";
        if (!(std::cin>>option)) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            option = -1;
        }
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        switch (option) {
            case 1:
                empty_term();
                get_recommendation();
                print_recommendation();
                break;
            case 0:
                menu_running = false;
                break;
            default:
                empty_term();
                print_recommendation();
                Print("Ogiltigt val\n\n");
        }

    }while (menu_running);
}

void Application::get_recommendation() {
    if (search_location()) {
        recommendations = std::move(planner->plan(latitude, longitude));
        empty_term();
        return;
    }
    empty_term();
}

bool Application::search_location() {
    std::string query = {};
    std::vector<Location> locations{};
    Print("Välkommen till platssökningen!\n\n");

    do {
        Print( "Skriv in önskad sökfras och tryck ENTER.\n"
               "För bästa resultat, skriv så mycket av platsnamnet som möjligt – helst fyra tecken eller fler\n\n"
               "För att avbryta sökningen, skriv 0 och tryck ENTER.\n\n");

        std::cout << "Input> ";
        std::getline(std::cin, query);

        if (query == "0") {
            empty_term();
            return false;
        }
        if (query != "0" && !query.empty()) {
            empty_term();
            locations = std::move(geocoder->search(query));
            if (!locations.empty()) {
                empty_term();
                std::ranges::sort(locations, sort_name_lat());
                if (choose_location(locations)) {
                    return true;
                }
            }
        }
    }while (true);
}

bool Application::choose_location(const std::vector<Location> &locations) {
    int location_index = -1;

    do {
        for (std::size_t i = 0; i < locations.size(); i++) {
            Print("{}. {}, {}, {}\n",
                (i + 1), locations[i].name, locations[i].region, locations[i].country);
        }

        Print( "\nHär är matchningarna till din sökning.\n"
                     "Välj plats genom att skriva in numret (1 – {}) och tryck ENTER.\n"
                     "Vill du gå tillbaka till sökningen? Skriv 0 och tryck ENTER.\n\n", locations.size());

        std::cout << "Input> ";
        if (!(std::cin>>location_index)) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            location_index = -1;
        }
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        if (location_index >= 1 && location_index <= locations.size()) {
            latitude = locations[location_index - 1].latitude;
            longitude = locations[location_index - 1].longitude;
            location_info = MakeString("{}, {}, {}", locations[location_index -1].name,
                locations[location_index -1].region, locations[location_index -1].country);
            empty_term();
            return true;
        } else if (location_index == 0) {
            empty_term();
            return false;
        } else {
            empty_term();
            Print("Ogiltigt val. Välj ett nummer mellan 1 och {}.\n"
                  "Eller 0 för att att gå tillbaka.\n\n", (locations.size() - 1));
        }

    } while (true);
}

void Application::print_recommendation() const
{
    if (!recommendations.empty())
    {
        Print("Dagens recommendationer för {} :\n\n", location_info);

        for (const auto& recommendation: recommendations) {
            Print("{}\n\n", recommendation);
        }
    }
}

Application::Application() : geocoder(std::make_unique<OpenMeteoGeocoder>()),
planner(std::make_unique<Planner>(std::make_unique<OpenMeteoProvider>())){
    planner->add_rule<WindAndRainRule>(8.0, 5.0, 50.0);
    planner->add_rule<ColdRule>(0.0);
    planner->add_rule<MildRule>(12.0, 5.0);
    planner->add_rule<UvIndexRule>(3.0, 8.0);
}

void Application::run() {
    menu();
}

void empty_term() {
    for (int i = 0; i <= 100; ++i) {
        std::cout << "\n";
    }
}
