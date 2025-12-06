//
// Created by jonathan on 9/24/25.
//

#ifndef LABB_2_1_SHAPE_H
#define LABB_2_1_SHAPE_H
#include <string>


class shape {
private:
    std::string color;

public:
    explicit shape(const std::string& color);
    virtual double get_area() = 0;
    std::string get_color();
    virtual ~shape() = default;
};


#endif //LABB_2_1_SHAPE_H