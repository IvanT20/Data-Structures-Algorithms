#ifndef HEAP_H
#define HEAP_H

#include <vector>
#include <utility>

/**
 * @class Heap
 * @brief A simple implementation of a heap data structure.
 * 
 * This provides the common functionalities associated with a heap.
 * It contains an insert, remove, and top method for working with data.
 * Furthermore, the heap can be turned into a max heap by setting the second template
 * argument to false.
 */
template <typename T, bool isMinHeap = true>
class Heap 
{

public:
    
    /**
     * @brief Default constructor for Heap.
     */
    Heap() = default;
    
    /**
     * @brief Makes a copy of the array and turns it into a heap.
     * @param arr The array to be copied.
     */
    Heap(std::vector<T> arr)
    {
        m_array = arr;
        buildHeap();
    }

    /**
     * @brief Reserves the number of elements in the arr.
     * @param numOfElements The number of elements to reserve.
     */
    explicit Heap(int numOfElements)
    {
        m_array.reserve(numOfElements);
    }

    void insert(T element)
    {

    }

    void remove()
    {

    }

    /**
     * @brief Retrieves the top element of the heap.
     * @return The top element of the heap.
     */
    T top() const
    {
        return m_array.front();
    }

    /**
     * @brief Retrieves the size of the heap.
     * @return The size of the heap.
     */
    std::size_t getSize() const
    {
        return m_array.size();
    }

    /**
     * @brief Retrieves the array representing the heap.
     * @return The heapified array.
     */
    std::vector<T> getArray() const
    {
        return m_array;
    }

private:

    std::vector<T> m_array{};

    /**
     * @brief Compares the value between two elements.
     * @return For minheap, returns true if a is greater than b. For maxHeap returns true if a is less than b.
     */
    bool cmp(const T& a, const T& b)
    {
        if constexpr(isMinHeap)
        {
            return a > b;
        }
        else
        {
            return a < b;
        }
    }

    /**
     * @brief Swaps elements from the parent node to the child nodes going down.
     * @param index The index of the parent node.
     */
    void siftDown(int index)
    {
        while (true)
        {
            int best = index;
            int leftChild = (index * 2) + 1;
            int rightChild = (index * 2) + 2;

            if (leftChild < static_cast<int>(m_array.size()) && cmp(m_array[best], m_array[leftChild]))
            {
                best = leftChild;
            }

            if (rightChild < static_cast<int>(m_array.size()) && cmp(m_array[best], m_array[rightChild]))
            {
                best = rightChild;
            }

            if (best == index)  // Parent node must currently be larger or less than its child nodes, so no swap is needed 
            {
                break;
            }

            std::swap(m_array[best], m_array[index]);
            index = best;
        }
    }

    /**
     * @brief Swaps elements from the parent node to the child nodes going up.
     * @param index The index of the parent node.
     */
    void siftUp(int index)
    {

    }

    /**
     * @brief Turns an array into a heap by satisfying the heap property.
     */
    void buildHeap()
    {
        int lastInternalNodeIndex = (static_cast<int>(m_array.size()) / 2) - 1;

        for (int i = lastInternalNodeIndex; i >= 0; --i)
        {
            siftDown(i);
        }
    }
};

#endif