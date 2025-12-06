cmake_minimum_required(VERSION 4.0)
project(Lab_1)

set(CMAKE_CXX_STANDARD 20)

add_executable(Lab_1 main.cpp
        int_buffer.h
        int_buffer.cpp
        int_sorted.cpp
        int_sorted.h
        buff_stream.h)
