//
// Created by jonathan on 9/16/25.
//

#include "int_sorted.h"

int_sorted::int_sorted(): data(nullptr, 0) {
}

int_sorted::int_sorted(int value): data(&value, 1) {
}

int_sorted::int_sorted(int_buffer &src) : data(src){
}

int_sorted::int_sorted(const int *source, std::size_t sz) : data(source, sz) {
        *this = sort(this->data.begin(), this->data.end());
}

void int_sorted::insert(int value) {
    *this = this->merge(int_sorted(value));
}

const int & int_sorted::operator[](std::size_t index) const {
    return data[index];
}


int_sorted int_sorted::merge(const int_sorted& merge_with) const {
    int_buffer temp(size() + merge_with.size());

    buff_stream A(this->data);
    buff_stream B(merge_with.data);
    buff_stream C(temp);

    while (A || B) {
        if (A && (!B || *A <= *B)) {
            C << A;
        } else {
            C << B;
        }
    }

    return int_sorted(temp);
}


int_sorted sort(const int *begin, const int *end) {
    if (begin == end) {
        return {};
    }
    if (begin == end - 1) {
        return int_sorted(*begin);
    }

    std::ptrdiff_t half = (end - begin)/2;
    const int* mid = begin + half;
    return sort(begin, mid).merge(sort(mid, end));
}


