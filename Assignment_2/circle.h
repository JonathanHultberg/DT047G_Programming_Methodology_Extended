//
// Created by jonathan on 9/24/25.
//

#ifndef LABB_2_1_CIRCLE_H
#define LABB_2_1_CIRCLE_H
#include "shape.h"


class circle: public shape {
private:
    double radius;
public:
    circle(const std::string& color, const double& radius);
    double get_area() override;
    [[nodiscard]] double get_radius() const;
};


#endif //LABB_2_1_CIRCLE_H