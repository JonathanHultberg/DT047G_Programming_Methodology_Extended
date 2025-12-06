//
// Created by jonathan on 9/24/25.
//

#ifndef LABB_2_1_RECTANGLE_H
#define LABB_2_1_RECTANGLE_H
#include "shape.h"


class rectangle: public shape{
private:
    double width, height;
public:
    rectangle(const std::string& color, const double& width, const double& height);
    double get_area() override;
    [[nodiscard]] double get_height() const;
    [[nodiscard]] double get_width() const;
};


#endif //LABB_2_1_RECTANGLE_H