#include <vector>
#include <iostream>

#include "heap.hpp"

int main()
{
    std::vector<int> arr = {6, 2, 1, -1, 0, 10, 9};
    Heap<int> heap(arr);

    for (auto& ele : heap.getArray())
    {
        std::cout << ele << ' ';
    }

    return 0;
}