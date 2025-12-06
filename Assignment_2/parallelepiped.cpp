//
// Created by jonathan on 9/24/25.
//

#include "parallelepiped.h"
#include <cmath>
#include <numbers>

parallelepiped::parallelepiped(const std::string& color, const double& width, const double& height, const double& depth, const double& tilt)
    : rectangle(color, width, height), depth(depth), tilt_angle(tilt) {
}

double parallelepiped::get_area() {
    if (tilt_angle != 90) {
        double slant_height = get_height() / std::sin(tilt_angle * (std::numbers::pi/180));

        return 2 * (depth * slant_height + depth * get_width() + slant_height * get_width());
    }
    return 2 * ( get_height() * get_width() + get_width() * depth + get_height() * depth);
}