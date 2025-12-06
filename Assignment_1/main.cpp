#include <chrono>
#include <ctime>
#include <iostream>
#include "int_buffer.h"
#include "int_sorted.h"

void selection_sort(int* first, std::size_t size) {

    for (int* start = first; start != (first + size); start++) {
        int* min = start;
        for (int* current = start; current != (first + size); current++) {
            if (*current < *min) {
                min = current;
            }
        }
        std::swap(*start, *min);
    }
}

int_buffer random_nr(std::size_t count, int min, int max) {
    int_buffer temp(count);
    std::srand(std::time(nullptr));

    for (int i = 0; i < count; i++) {
        temp[i] = rand() % (max - min + 1) + min;
    }

    return temp;
}

int_buffer f(int_buffer buf) {

    int numb = 1;
    for (int* i = buf.begin(); i != buf.end(); ++i) { //Rätt begin och end, använder den icke-const
        *i = numb;
        ++numb;
    }

    for (const int* i = buf.begin(); i != buf.end(); ++i) { //Fel? använder fortfarande icke-const begin och end
        std::cout << *i << ", ";
    }

    return buf;
}

int main() {

    int_buffer buff1 (random_nr(400000, 1, 400000));
    int_buffer buff2 = buff1;
    int_buffer buff3 = buff1;

    auto start_int_sorted = std::chrono::high_resolution_clock::now();
    int_sorted int_sorted1(buff1.begin(), buff1.size());
    auto end_int_sorted = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double, std::milli> time_int_sorted_ms = end_int_sorted - start_int_sorted;

    auto start_selection_sort = std::chrono::high_resolution_clock::now();
    selection_sort(buff2.begin(), buff2.size());
    auto end_selection_sort = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double, std::milli> time_selection_sort_ms = end_selection_sort - start_selection_sort;

    auto start_algorithm_sort = std::chrono::high_resolution_clock::now();
    std::sort(buff3.begin(), buff3.end());
    auto end_algorithm_sort = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double, std::milli> time_algorithm_sort_ms = end_algorithm_sort - start_algorithm_sort;

    std::cout << "Int_Sorted: " << time_int_sorted_ms.count() << " ms" << std::endl;
    std::cout << "SelectionSort: " << time_selection_sort_ms.count() << " ms" << std::endl;
    std::cout << "AlgorithmSort: " << time_algorithm_sort_ms.count() << " ms" << std::endl;



    f(int_buffer(10)); //anropar CTOR på formen int_buffert(size_t); anropar destruktorn på formen ~int_buffer();
    int_buffer buf2 = f(int_buffer(10));

    for (const auto& e: buf2) {
        std::cout << e << ", ";
    }

    buf2 = f(buf2);

    for (const auto& e: buf2) {
        std::cout << e << ", ";
    }

    return 0;
}
