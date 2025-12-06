//
// Created by jonathan on 9/24/25.
//

#include "circle.h"
#include <numbers>

circle::circle(const std::string& color, const double& radius) : shape(color), radius(radius) {
}

double circle::get_area() {
    return std::numbers::pi * radius * radius;
}

double circle::get_radius() const {
    return radius;
}