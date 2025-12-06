//
// Created by jonat on 2025-09-09.
//
#include "int_buffer.h"



int_buffer::int_buffer (std::size_t sz) : first(new int[sz]), last(first + sz) {
}

int_buffer::int_buffer(const int* source, std::size_t sz) : int_buffer(sz) {
    std::copy_n(source, sz, first);
}

int_buffer::int_buffer(const int_buffer& src) : int_buffer(src.begin(), src.size()) {
}

int_buffer::int_buffer(int_buffer&& rhs) noexcept : first(nullptr), last(nullptr) {
    swap(rhs);
}

int_buffer & int_buffer::operator=(const int_buffer &rhs) {

    int_buffer tmp = rhs;
    swap(tmp);

    return *this;
}

int_buffer & int_buffer::operator=(int_buffer &&rhs) noexcept {

    swap(rhs);

    return *this;
}

int & int_buffer::operator[](std::size_t index) {
    return first[index];
}

const int & int_buffer::operator[](std::size_t index) const {
    return first[index];
}

std::size_t int_buffer::size() const {
    return std::distance(first, last);
}

int_buffer::~int_buffer() {
    delete[] first;
}

void int_buffer::swap(int_buffer& obj) noexcept {
    std::swap(obj.first, first);
    std::swap(obj.last, last);
}



