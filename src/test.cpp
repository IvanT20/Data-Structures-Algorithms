#include <vector>
#include <iostream>

#include "heap.hpp"

int main()
{
    Heap<int> heap{};
    heap.insert(5);
    heap.insert(6);
    heap.insert(4);
    heap.insert(3);

    for (auto& ele : heap.getArray())
    {
        std::cout << ele << ' ';
    }

    return 0;
}