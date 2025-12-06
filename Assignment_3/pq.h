//
// Created by jonat on 2025-10-04.
//

#ifndef LAB_3_PQ_H
#define LAB_3_PQ_H
#include <functional>

template<typename T, typename COMP = std::less<>>
class pq {
private:
    std::vector<T> data;
    COMP comp;

    void heapify_up(std::size_t index);
    void heapify_down(std::size_t index);
    void build_heap();

public:
    pq();
    explicit pq(COMP comp);
    template<typename IT>
    pq(IT first, IT last, COMP comp = COMP());

    void push(T element);
    T top() const;
    T pop();
    [[nodiscard]] bool empty() const;
    [[nodiscard]] size_t size() const;
};

template<typename T, typename COMP>
void pq<T, COMP>::heapify_up(std::size_t index) {

    while (true) {
        size_t parent = (index - 1) / 2;

        if (comp(data[index], data[parent])) {
            std::swap(data[index], data[parent]);
            index = parent;
        } else {
            return;
        }
    }
}

template<typename T, typename COMP>
void pq<T, COMP>::heapify_down(std::size_t index) {
    std::size_t size = data.size();

    while (true) {
        std::size_t left_child = 2 * index + 1;
        std::size_t right_child = 2 * index + 2;
        std::size_t largest = index;

        if (left_child < size && comp(data[left_child], data[largest])) {
            largest = left_child;
        }

        if (right_child < size && comp(data[right_child], data[largest])) {
            largest = right_child;
        }

        if (largest != index) {
            std::swap(data[index], data[largest]);
            index = largest;
        } else {
            return;
        }
    }
}

template<typename T, typename COMP>
void pq<T, COMP>::build_heap() {
    if (data.empty()) {
        return;
    }

    for (std::size_t index = data.size() / 2; index-- >0;) {
        heapify_down(index);
    }
}

template<typename T, typename COMP>
pq<T, COMP>::pq() : data{}, comp{} {
}

template<typename T, typename COMP>
pq<T, COMP>::pq(COMP comp) : data{}, comp(comp) {
}

template<typename T, typename COMP>
template<typename IT>
pq<T, COMP>::pq(IT first, IT last, COMP comp) : data(first, last), comp(comp) {
    build_heap();
}

template<typename T, typename COMP>
void pq<T, COMP>::push(T element) {
    data.push_back(element);
    heapify_up(data.size() - 1);
}

template<typename T, typename COMP>
T pq<T, COMP>::top() const {
    return data[0];
}

template<typename T, typename COMP>
T pq<T, COMP>::pop() {
    T top = std::move(data[0]);
    std::swap(data[0], data.back());
    data.pop_back();
    if (!empty()) {
        heapify_down(0);
    }
    return top;
}

template<typename T, typename COMP>
bool pq<T, COMP>::empty() const {
    return data.empty();
}

template<typename T, typename COMP>
size_t pq<T, COMP>::size() const {
    return data.size();
}



#endif //LAB_3_PQ_H
