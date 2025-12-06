//
// Created by jonathan on 9/17/25.
//

#ifndef LAB_1_BUFF_STREAM_H
#define LAB_1_BUFF_STREAM_H
#include "int_buffer.h"


struct buff_stream {
private:
    int* first;
    int* last;

public:
    explicit buff_stream(const int_buffer& src):first(src.begin()), last(src.end()) {};
    operator bool() const { return first != last; };
    buff_stream& operator<< (buff_stream& rhs) {
        *this->first++ = *rhs.first++;
        return *this;
    };
    std::size_t size() const { return last - first; };
    int& operator*() { return *first; };
};


#endif //LAB_1_BUFF_STREAM_H