#ifndef HEAP_H
#define HEAP_H

#include <vector>
#include <utility>

/**
 * @class Heap
 * @brief A simple implementation of a heap data structure
 * 
 * This provides the common functionalities associated with a heap.
 * It contains an insert, remove, and top
 */
template <typename T, bool isMinHeap = true>
class Heap 
{

public:

    Heap() = default;
    
    Heap(std::vector<T>& arr)
    {

    }

    explicit Heap(int numOfElements)
    {
        m_data.reserve(numOfElements);
    }

    void 

private:

    std::vector<T> m_data{};

    bool cmp(const T& a, const T& b)
    {
        if constexpr(isMinHeap)
        {
            return a > b;
        }
        else
        {
            return a < b
        }
    }

};

#endif