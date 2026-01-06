#ifndef QUICKSELECT_H
#define QUICKSELECT_H

#include <vector>
#include <cstddef>

// ---------- Simpel min-heap priority queue til ints ----------
class PriorityQueue {
public:
    explicit PriorityQueue(std::size_t capacity = 0);

    // Indsæt nyt element
    void push(int x, long long &opCount);

    // Mindste element (fjerner det ikke)
    int top(long long &opCount) const;

    // Fjern mindste element
    void pop(long long &opCount);

    bool empty() const { return heap.empty(); }
    std::size_t size() const { return heap.size(); }

private:
    std::vector<int> heap;  // heap[0] er mindst

    void percolateUp(std::size_t i, long long &opCount);
    void percolateDown(std::size_t i, long long &opCount);
};

// ---------- QuickSelect algoritmer ----------
class QuickSelect {
public:
    // k er 1-baseret: k = 1 betyder mindste element
    // Bruger priority queue – burde være O(N log N)
    static int selectWithPQ(const std::vector<int> &a, int k, long long &opCount);

    // Klassisk QuickSelect – forventet O(N)
    static int quickSelect(std::vector<int> &a, int k, long long &opCount);

    // Enkel eksperiment-funktion (kan kaldes fra main)
    static void runExperiments();

private:
    static int quickSelectRec(std::vector<int> &a, int left, int right, int k, long long &opCount);
    static int partition(std::vector<int> &a, int left, int right, int pivotIndex, long long &opCount);
};

#endif
