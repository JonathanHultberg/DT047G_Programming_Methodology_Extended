//
// Created by jonathan on 9/16/25.
//

#ifndef LAB_1_INT_SORTED_H
#define LAB_1_INT_SORTED_H

#include <cstddef>
#include <algorithm>
#include "int_buffer.h"
#include "buff_stream.h"



class int_sorted {
private:
    int_buffer data;


    int_sorted();
    explicit int_sorted(int value);
    explicit int_sorted(int_buffer& src);
public:
    int_sorted(const int* source, std::size_t size);
    std::size_t size() const { return data.size(); };
    void insert(int value);
    const int& operator[](std::size_t index) const;
    [[nodiscard]] const int* begin() const { return data.begin(); };
    [[nodiscard]] const int* end() const { return data.begin()+ data.size(); };
    [[nodiscard]] int_sorted merge(const int_sorted& merge_with) const;

    friend int_sorted sort(const int *begin, const int *end);
};

int_sorted sort(const int *begin, const int *end);

#endif //LAB_1_INT_SORTED_H