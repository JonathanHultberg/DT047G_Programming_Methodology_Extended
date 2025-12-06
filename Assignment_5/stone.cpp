//
// Created by jonat on 2025-10-15.
//

#include "stone.h"

Stone::Stone(const std::string& name, double weight)
: name(name), weight(weight){}

bool Stone::operator==(const Stone &rhs) const {
    return name == rhs.name;
}
