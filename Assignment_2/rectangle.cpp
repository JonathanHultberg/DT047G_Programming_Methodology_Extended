//
// Created by jonathan on 9/24/25.
//

#include "rectangle.h"

rectangle::rectangle(const std::string& color, const double& width, const double& height)
: shape(color), width(width), height(height) {
}

double rectangle::get_area() {
    return width * height;
}

double rectangle::get_height() const{
    return height;
}

double rectangle::get_width() const {
    return width;
}