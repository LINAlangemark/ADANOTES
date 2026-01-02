#include "prioQ.h"
#include <algorithm>
#include <stdexcept>

// ---------------- Basic operations ----------------

bool PrioQ::isEmpty() const
{
    return heap.empty();
}

int PrioQ::top() const
{
    if (isEmpty())
        throw std::runtime_error("Empty priority queue");
    return heap[0];
}

void PrioQ::push(int x)
{
    heap.push_back(x);
    percolateUp(heap.size() - 1);
}

void PrioQ::pop()
{
    if (isEmpty())
        return;

    heap[0] = heap.back();
    heap.pop_back();
    percolateDown(0);
}

// ---------------- changePriority ----------------

void PrioQ::changePriority(int fromP, int toP)
{
    // 1. find element
    int index = -1;
    for (int i = 0; i < heap.size(); ++i)
    {
        if (heap[i] == fromP)
        {
            index = i;
            break;
        }
    }

    if (index == -1)
        return; // element not found (precondition violated)

    // 2. replace value
    heap[index] = toP;

    // 3. restore heap order
    if (toP > fromP)
        percolateUp(index);
    else
        percolateDown(index);
}

// ---------------- Heap helpers ----------------

void PrioQ::percolateUp(int i)
{
    while (i > 0 && heap[parent(i)] < heap[i])
    {
        std::swap(heap[i], heap[parent(i)]);
        i = parent(i);
    }
}

void PrioQ::percolateDown(int i)
{
    int size = heap.size();

    while (true)
    {
        int l = left(i);
        int r = right(i);
        int largest = i;

        if (l < size && heap[l] > heap[largest])
            largest = l;
        if (r < size && heap[r] > heap[largest])
            largest = r;

        if (largest != i)
        {
            std::swap(heap[i], heap[largest]);
            i = largest;
        }
        else
            break;
    }
}
