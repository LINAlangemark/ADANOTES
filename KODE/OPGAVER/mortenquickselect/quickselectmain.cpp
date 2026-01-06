#include <iostream>   // cout, endl
#include <vector>     // std::vector
#include <cstdlib>    // rand, srand
#include <ctime>      // time
#include <iomanip>    // setw, left, right
#include <algorithm>  // swap
#include <string>     // to_string
// ---------------- Priority Queue ----------------
class PriorityQueue {
private:
    std::vector<int> heap;
    int instructions = 0;

    void bubbleUp(int idx) {
        instructions++;
        while (idx > 0) {
            int parent = (idx - 1) / 2;
            instructions++;
            if (heap[idx] > heap[parent]) {
                int temp = heap[idx];
                heap[idx] = heap[parent];
                heap[parent] = temp;
                idx = parent;
                instructions += 3;
            } else break;
        }
    }

    void bubbleDown(int idx) {
        int n = heap.size();
        instructions++;
        while (true) {
            int largest = idx;
            int left = 2 * idx + 1;
            int right = 2 * idx + 2;

            if (left < n && heap[left] > heap[largest]) largest = left;
            if (right < n && heap[right] > heap[largest]) largest = right;
            instructions += 2;

            if (largest != idx) {
                int temp = heap[idx];
                heap[idx] = heap[largest];
                heap[largest] = temp;
                idx = largest;
                instructions += 3;
            } else break;
        }
    }

public:
    void insert(int val) {
        heap.push_back(val);
        instructions++;
        bubbleUp(heap.size() - 1);
    }

    int extractMax() {
        if (heap.empty()) return -1;
        int maxVal = heap[0];
        heap[0] = heap.back();
        heap.pop_back();
        instructions++;
        bubbleDown(0);
        return maxVal;
    }

    int getInstructions() const { return instructions; }
};

// ---------------- PQ Selection ----------------
int kthSmallestPQ(const std::vector<int> &arr, int k, int &instructions) {
    PriorityQueue pq;
    for (size_t i = 0; i < arr.size(); i++) {
        pq.insert(arr[i]);
    }
    for (size_t i = 0; i < arr.size() - k; i++) {
        pq.extractMax();
    }
    instructions = pq.getInstructions();
    return pq.extractMax();
}

// ---------------- QuickSelect ----------------
template <typename Comparable>
const Comparable & median3(std::vector<Comparable> & a, int left, int right, int &instructions) {
    int center = (left + right) / 2;
    int instructions_cost = 1;
    instructions += 1; // comparisons
    if (a[center] < a[left]) { std::swap(a[left], a[center]); instructions += 3; }
    if (a[right] < a[left]) { std::swap(a[left], a[right]); instructions += 3; }
    if (a[right] < a[center]) { std::swap(a[center], a[right]); instructions += 3; }
    // Place pivot at right-1
    std::swap(a[center], a[right-1]); instructions += 3;
    return a[right-1];
}
template <typename Comparable>
void insertionSort(std::vector<Comparable> &a, int left, int right, int &instructions) {
    for (int i = left + 1; i <= right; ++i) {
        Comparable tmp = a[i];
        instructions++;
        int j = i;
        while (j > left && tmp < a[j - 1]) {
            instructions++;
            a[j] = a[j - 1];
            j--;
            instructions++;
        }
        a[j] = tmp;
        instructions++;
    }
}
template <typename Comparable>
void quickSelect(std::vector<Comparable> & a, int left, int right, int k, int &instructions)
{
    if(left + 10 <= right)
    {
        const Comparable & pivot = median3(a, left, right, instructions);
        int i = left, j = right - 1;
        for(;;)
        {
            while(a[++i] < pivot) { instructions++; }
            while(pivot < a[--j]) { instructions++; }
            if(i < j) { std::swap(a[i], a[j]); instructions += 3; }
            else break;
        }
        std::swap(a[i], a[right - 1]); instructions += 3;

        if(k <= i)
            quickSelect(a, left, i - 1, k, instructions);
        else if(k > i + 1)
            quickSelect(a, i + 1, right, k, instructions);
    }
    else
        insertionSort(a, left, right, instructions);
}

// ---------------- Run PQ + QuickSelect on random array ----------------
void runRandomTest(int N) {
    std::vector<int> arr(N);
    for (int j = 0; j < N; j++)
        arr[j] = std::rand() % 10000;

    int k = N / 2; // median
    int instrPQ, instrQS;

    // Priority Queue selection
    kthSmallestPQ(arr, k, instrPQ);

    // QuickSelect selection
    std::vector<int> arrCopyQS = arr;
    instrQS = 0;
    quickSelect(arrCopyQS, 0, N - 1, k - 1, instrQS);

    std::cout << std::left << std::setw(12) << N 
              << std::right << std::setw(20) << instrPQ 
              << std::right << std::setw(20) << instrQS 
              << std::endl;
}

// ---------------- Run PQ + QuickSelect on fixed array ----------------
void runFixedTest(int N, const std::vector<int> &fixedData) {
    std::vector<int> arrFixed;
    while (arrFixed.size() < static_cast<size_t>(N)) {
        for (size_t f = 0; f < fixedData.size() && arrFixed.size() < static_cast<size_t>(N); f++)
            arrFixed.push_back(fixedData[f]);
    }

    int k = N / 2; // median
    int instrPQ, instrQS;

    // Priority Queue selection
    kthSmallestPQ(arrFixed, k, instrPQ);

    // QuickSelect selection
    std::vector<int> arrCopyQS = arrFixed;
    instrQS = 0;
    quickSelect(arrCopyQS, 0, N - 1, k - 1, instrQS);

    std::cout << std::left << std::setw(12) << (std::to_string(N) + " (fixed)") 
              << std::right << std::setw(20) << instrPQ 
              << std::right << std::setw(20) << instrQS 
              << std::endl;
}

// ---------------- Main ----------------
int main() {
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    // Table headers
    std::cout << std::left << std::setw(12) << "N" 
              << std::right << std::setw(20) << "PQ Instructions" 
              << std::right << std::setw(20) << "QuickSelect Instr" 
              << std::endl;
    std::cout << "----------------------------------------------------------" << std::endl;

    std::vector<int> testSizes = {10, 100, 500, 1000, 5000};
    std::vector<int> fixedData = {
        14, 17, 16, 28, 22, 65, 29, 31, 30, 26, 23, 89, 64, 35, 32, 48, 
        47, 46, 45, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60
    };

    for (size_t i = 0; i < testSizes.size(); i++) {
        int N = testSizes[i];
        //runRandomTest(N);
        runFixedTest(N, fixedData);
    }

    return 0;
}