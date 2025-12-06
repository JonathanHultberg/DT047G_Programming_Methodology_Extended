//
// Created by jonathan on 9/24/25.
//

#include "square.h"

square::square(const std::string& color, const double& side): shape(color), side(side) {
}

double square::get_area() {
    return side * side;
}