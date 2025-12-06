cmake_minimum_required(VERSION 4.0)
project(Labb_2)

set(CMAKE_CXX_STANDARD 20)

add_executable(Labb_2_1 main.cpp
        shape.cpp
        shape.h
        circle.cpp
        circle.h
        cylinder.cpp
        cylinder.h
        rectangle.cpp
        rectangle.h
        parallelepiped.cpp
        parallelepiped.h
        rounded_rectangle.cpp
        rounded_rectangle.h
        square.cpp
        square.h)
