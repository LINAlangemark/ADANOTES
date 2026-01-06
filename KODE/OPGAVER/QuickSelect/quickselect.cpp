#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <cmath>

#include "quickselect.h"

// ===================== PriorityQueue implementation =====================

PriorityQueue::PriorityQueue(std::size_t capacity) {
    heap.reserve(capacity);
}

void PriorityQueue::push(int x, long long &opCount) {
    heap.push_back(x);                  // indsæt bagerst
    ++opCount;

    percolateUp(heap.size() - 1, opCount);
}

int PriorityQueue::top(long long &opCount) const {
    ++opCount; // vi tæller læsning/adgang
    return heap.front();
}

void PriorityQueue::pop(long long &opCount) {
    if (heap.empty()) return;

    // Flyt sidste element til roden og heapify nedad
    heap[0] = heap.back(); ++opCount;
    heap.pop_back();                    ++opCount;

    if (!heap.empty())
        percolateDown(0, opCount);
}

void PriorityQueue::percolateUp(std::size_t i, long long &opCount) {
    while (i > 0) {
        std::size_t parent = (i - 1) / 2;
        ++opCount; // sammenligning
        if (heap[i] < heap[parent]) {
            std::swap(heap[i], heap[parent]); // én operation vi tæller
            ++opCount;
            i = parent;
        } else break;
    }
}

void PriorityQueue::percolateDown(std::size_t i, long long &opCount) {
    std::size_t n = heap.size();
    while (true) {
        std::size_t left  = 2 * i + 1;
        std::size_t right = 2 * i + 2;
        std::size_t smallest = i;

        if (left < n) {
            ++opCount;
            if (heap[left] < heap[smallest]) smallest = left;
        }
        if (right < n) {
            ++opCount;
            if (heap[right] < heap[smallest]) smallest = right;
        }

        if (smallest != i) {
            std::swap(heap[i], heap[smallest]);
            ++opCount;
            i = smallest;
        } else break;
    }
}

// ===================== QuickSelect med PQ (Problem 1) =====================

// O(N log N): put alle elementer i en min-heap og pop k gange
int QuickSelect::selectWithPQ(const std::vector<int> &a, int k, long long &opCount) {
    opCount = 0;
    PriorityQueue pq(a.size());
    for (int x : a) {
        pq.push(x, opCount);
    }

    int value = -1;
    for (int i = 0; i < k; ++i) {
        value = pq.top(opCount);
        pq.pop(opCount);
    }
    return value;
}

// ===================== Klassisk QuickSelect (Problem 2) =====================

int QuickSelect::quickSelect(std::vector<int> &a, int k, long long &opCount) {
    opCount = 0;
    if (k < 1 || k > (int)a.size()) {
        throw std::out_of_range("k out of range");
    }
    // gør k 0-baseret
    return quickSelectRec(a, 0, (int)a.size() - 1, k - 1, opCount);
}

int QuickSelect::quickSelectRec(std::vector<int> &a, int left, int right, int k, long long &opCount) {
    while (true) {
        if (left == right) {
            ++opCount;
            return a[left];
        }

        int pivotIndex = left + (right - left) / 2; // simpel pivot
        int pivotNewIndex = partition(a, left, right, pivotIndex, opCount);
        if (k == pivotNewIndex) {
            ++opCount;
            return a[k];
        } else if (k < pivotNewIndex) {
            ++opCount;
            right = pivotNewIndex - 1;
        } else {
            ++opCount;
            left = pivotNewIndex + 1;
        }
    }
}

int QuickSelect::partition(std::vector<int> &a, int left, int right, int pivotIndex, long long &opCount) {
    int pivotValue = a[pivotIndex]; ++opCount;

    std::swap(a[pivotIndex], a[right]); ++opCount; // pivot til enden
    int storeIndex = left;

    for (int i = left; i < right; ++i) {
        ++opCount; // sammenligning
        if (a[i] < pivotValue) {
            std::swap(a[i], a[storeIndex]);
            ++opCount;
            ++storeIndex;
        }
    }

    std::swap(a[storeIndex], a[right]); ++opCount; // pivot på sin plads
    return storeIndex;
}

// ===================== Eksperimenter (Problem 1 + 2) =====================

void QuickSelect::runExperiments() {
    std::mt19937 rng(42);
    std::uniform_int_distribution<int> dist(0, 1000000);

    std::cout << "N\tk\tPQ_ops\tPQ_ops/(N*log2N)\tQS_ops\tQS_ops/N\n";

    for (int N : {1000, 2000, 4000, 8000, 16000}) {
        std::vector<int> data(N);
        for (int &x : data) x = dist(rng);

        int k = N / 2; // cirka median

        long long opsPQ = 0, opsQS = 0;

        int v1 = selectWithPQ(data, k, opsPQ);

        std::vector<int> copy = data;
        int v2 = quickSelect(copy, k, opsQS);

        if (v1 != v2) {
            std::cerr << "Error: different answers!" << std::endl;
        }

        double log2N = std::log2((double)N);
        std::cout << N << '\t' << k << '\t'
                  << opsPQ << '\t' << (opsPQ / (N * log2N)) << '\t'
                  << opsQS << '\t' << (double)opsQS / N << '\n';
    }
}
