//
// Created by jonat on 2025-09-08.
//
#ifndef LAB_1_INT_BUFFER_H
#define LAB_1_INT_BUFFER_H

#include <cstdlib>
#include <algorithm> //används för copy_n
#include <iterator>


class int_buffer {
private:
    int* first;
    int* last;

    void swap(int_buffer& obj) noexcept;
public:
    explicit int_buffer(std::size_t size);
    int_buffer(const int* source, std::size_t size);
    int_buffer(const int_buffer& rhs); //copy
    int_buffer(int_buffer&& rhs) noexcept; //move
    int_buffer& operator=(const int_buffer& rhs); //copy-assign
    int_buffer& operator=(int_buffer&& rhs) noexcept; //move-assign
    int& operator[](std::size_t index);
    const int& operator[](std::size_t index) const;
    std::size_t size() const;
    int* begin(){return first;};
    int* end() {return last;};
    [[nodiscard]] int* begin() const {return first;};
    [[nodiscard]] int* end() const {return last;};
    ~int_buffer();
};

#endif //LAB_1_INT_BUFFER_H