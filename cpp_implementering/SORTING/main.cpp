#include <iostream>
#include <vector>

// ---------- Hjælpefunktion ----------
void printArray(const std::vector<int>& arr) {
    for (int x : arr)
        std::cout << x << " ";
    std::cout << "\n";
}

// =====================================================
// INSERTION SORT
// =====================================================
void insertionSort(std::vector<int> arr) {
    std::cout << "\n--- INSERTION SORT ---\n";
    printArray(arr);

    for (int i = 1; i < arr.size(); i++) {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;

        printArray(arr);
    }
}

// =====================================================
// SELECTION SORT
// =====================================================
void selectionSort(std::vector<int> arr) {
    std::cout << "\n--- SELECTION SORT ---\n";
    printArray(arr);

    for (int i = 0; i < arr.size(); i++) {
        int minIdx = i;
        for (int j = i + 1; j < arr.size(); j++) {
            if (arr[j] < arr[minIdx])
                minIdx = j;
        }
        std::swap(arr[i], arr[minIdx]);
        printArray(arr);
    }
}

// =====================================================
// BUBBLE SORT
// =====================================================
void bubbleSort(std::vector<int> arr) {
    std::cout << "\n--- BUBBLE SORT ---\n";
    printArray(arr);

    for (int i = 0; i < arr.size(); i++) {
        for (int j = 0; j < arr.size() - i - 1; j++) {
            if (arr[j] > arr[j + 1])
                std::swap(arr[j], arr[j + 1]);
        }
        printArray(arr);
    }
}

// =====================================================
// MERGE SORT
// =====================================================
void merge(std::vector<int>& arr, int l, int m, int r) {
    std::vector<int> left(arr.begin() + l, arr.begin() + m + 1);
    std::vector<int> right(arr.begin() + m + 1, arr.begin() + r + 1);

    int i = 0, j = 0, k = l;
    while (i < left.size() && j < right.size()) {
        arr[k++] = (left[i] <= right[j]) ? left[i++] : right[j++];
    }
    while (i < left.size()) arr[k++] = left[i++];
    while (j < right.size()) arr[k++] = right[j++];
}

void mergeSort(std::vector<int>& arr, int l, int r) {
    if (l >= r) return;
    int m = (l + r) / 2;
    mergeSort(arr, l, m);
    mergeSort(arr, m + 1, r);
    merge(arr, l, m, r);
}

void showMergeSort(std::vector<int> arr) {
    std::cout << "\n--- MERGE SORT ---\n";
    printArray(arr);
    mergeSort(arr, 0, arr.size() - 1);
    printArray(arr);
}

// =====================================================
// HEAP SORT
// =====================================================
void heapify(std::vector<int>& arr, int n, int i) {
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n && arr[l] > arr[largest]) largest = l;
    if (r < n && arr[r] > arr[largest]) largest = r;

    if (largest != i) {
        std::swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSort(std::vector<int> arr) {
    std::cout << "\n--- HEAP SORT ---\n";
    printArray(arr);

    for (int i = arr.size() / 2 - 1; i >= 0; i--)
        heapify(arr, arr.size(), i);

    for (int i = arr.size() - 1; i > 0; i--) {
        std::swap(arr[0], arr[i]);
        heapify(arr, i, 0);
        printArray(arr);
    }
}

// =====================================================
// QUICK SORT
// =====================================================
int partition(std::vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            std::swap(arr[i], arr[j]);
        }
    }
    std::swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(std::vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void showQuickSort(std::vector<int> arr) {
    std::cout << "\n--- QUICK SORT ---\n";
    printArray(arr);
    quickSort(arr, 0, arr.size() - 1);
    printArray(arr);
}

// =====================================================
// MAIN
// =====================================================
int main() {
    std::vector<int> data = {5, 2, 9, 1, 5, 6};

    insertionSort(data);
    selectionSort(data);
    bubbleSort(data);

    showMergeSort(data);
    heapSort(data);
    showQuickSort(data);

    return 0;
}
