//
// Created by jonathan on 9/24/25.
//

#ifndef LABB_2_1_SQUARE_H
#define LABB_2_1_SQUARE_H
#include "shape.h"

class square final : public shape {
private:
    double side;

public:
    square(const std::string& color, const double& side);
    double get_area() override;
};


#endif //LABB_2_1_SQUARE_H