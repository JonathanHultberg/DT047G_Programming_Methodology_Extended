//
// Created by jonathan on 9/24/25.
//

#ifndef LABB_2_1_PARALLELEPIPED_H
#define LABB_2_1_PARALLELEPIPED_H
#include "rectangle.h"


class parallelepiped final : public rectangle {
private:
    double depth;
    double tilt_angle;
public:
    parallelepiped(const std::string& color, const double& width, const double& height, const double& depth, const double& tilt = 90);
    double get_area() override;
};


#endif //LABB_2_1_PARALLELEPIPED_H