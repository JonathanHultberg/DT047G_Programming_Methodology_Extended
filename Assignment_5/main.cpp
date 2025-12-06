#include <algorithm>
#include <iostream>
#include <vector>
#include <algorithm>
#include <array>
#include <numeric>

#include "stone.h"

class MyPrint {
public:
    void operator()(const Stone& s) const {
     std::cout << "Name: " << s.get_name() << " | Weight: " << s.get_weight() << "\n";
    }
};

class HeavierThan {
private:
    double weight_limit;
public:
    explicit HeavierThan(const double& w) : weight_limit(w) {}
    bool operator()(const Stone& s) const {return s.get_weight() > weight_limit;}
};

class SameName {
public:
    bool operator()(const Stone& stone1, const Stone& stone2) const { return stone1 == stone2; }
};

class MyBinOp {
public:
    double operator()(double acc, const Stone& stone) { return acc + stone.get_weight(); }
};

class MyUnOp {
public:
    double operator()(const Stone& stone) { return stone.get_weight(); }
};

class MyFunc {
private:
    double m;
public:
    explicit MyFunc(const double& m) : m(m) {}
    double operator()(double& x) { return x - m; }
};

int main() {
    std::array<Stone, 6> arr = {
        Stone("Sisyfos", 666.666),
        Stone("Thor's Pebble", 0.1),
        Stone("Medusa", 15.55),
        Stone("Granite Prime", 130.77),
        Stone("Quartzzilla", 69.69),
        Stone("Dwayne", 537.6)
    };

    std::vector<Stone> stones(arr.begin(), arr.end());

    //_______________________________1__________________________________________

    std::for_each(stones.begin(), stones.end(), MyPrint());

    std::cout << "\n\n";
    //_______________________________2__________________________________________

    double threshold = 10.0;

    auto it = std::find_if(stones.begin(), stones.end(), HeavierThan(threshold));

    if (it != stones.end()) {
        std::cout << "First stone heavier than " << threshold << " kg:\n";
        MyPrint()(*it);
    } else {
        std::cout << "No stone heavier than " << threshold << " kg found.\n";
    }

    std::cout << "\n\n";
    //_______________________________3__________________________________________

    auto it2 = std::adjacent_find(stones.begin(), stones.end(), SameName());

    if (it2 != stones.end()) {
        std::cout << "Found adjacent stones with the same name:\n";
        MyPrint()(*it2);
        std::cout << "and\n";
        MyPrint()(*(it2 + 1));
    } else {
        std::cout << "No adjacent stones with identical names.\n";
    }

    std::cout << "\n\n";
    //_______________________________4__________________________________________

    bool are_equal = std::equal(arr.begin(), arr.end(), stones.begin());

    if (are_equal) {
        std::cout << "Array and vector contain the same stones!\n";
    } else {
        std::cout << "They differ.\n";
    }

    std::cout << "\n\n";
    //_______________________________5__________________________________________

    auto sub_first = arr.begin() + 2;
    auto sub_last = arr.begin() + 5; //[2,5)

    auto it3 = std::search(stones.begin(), stones.end(), sub_first, sub_last);

    if (it != stones.end()) {
        auto pos = std::distance(stones.begin(), it3);
        std::cout << "Found subsequence with start index " << pos << ":\n";
        for (auto p = it3; p != it3 + (sub_last - sub_first); ++p) {
            MyPrint()(*p);
        }
    } else {
        std::cout << "No matching subsequence found\n";
    }

    std::cout << "\n\n";
    //_______________________________6__________________________________________

    double total_weight = std::accumulate(stones.begin(), stones.end(), 0.0, MyBinOp());
    double mean = total_weight / stones.size();
    std::cout << "Mean: " << mean << "\n";

    std::cout << "\n\n";
    //_______________________________7__________________________________________

    std::vector<double> v2 (stones.size());

    std::transform(stones.begin(), stones.end(), v2.begin(), MyUnOp());

    //_______________________________8__________________________________________

    std::transform(v2.begin(), v2.end(), v2.begin(), MyFunc(mean));

    //_______________________________9__________________________________________

    std::sort(v2.begin(), v2.end());

    for (const auto& s : v2) {
        std::cout << s << ", ";
    }
}