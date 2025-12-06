//
// Created by jonat on 2025-10-15.
//

#ifndef LAB_5_STONE_H
#define LAB_5_STONE_H
#include <string>


class Stone {
private:
    std::string name;
    double weight;
public:
    Stone(const std::string& name, double weight);
    bool operator==(const Stone& rhs) const;
    std::string get_name() const {return name;};
    double get_weight() const {return weight;};
};


#endif //LAB_5_STONE_H