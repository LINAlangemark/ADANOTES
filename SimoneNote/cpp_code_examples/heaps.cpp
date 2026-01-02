#include <iostream>
#include <vector>

void heapify_up(std::vector<int>& arr, int i) {
    while (i > 1 && arr[i] < arr[i / 2]) {
        std::swap(arr[i], arr[i / 2]);
        i /= 2;
    }
}

void heapify_down(std::vector<int>& arr, int i, int n) {
    int left = 2 * i;
    int right = 2 * i + 1;
    int smallest = i;
    if (left <= n && arr[left] < arr[smallest]) {
        smallest = left;
    }
    if (right <= n && arr[right] < arr[smallest]) {
        smallest = right;
    }
    if (smallest != i) {
        std::swap(arr[i], arr[smallest]);
        heapify_down(arr, smallest, n);
    }
}

void insert(std::vector<int>& arr, int key) {
    arr.push_back(key);
    heapify_up(arr, arr.size() - 1);
}

void delete_min(std::vector<int>& arr) {
    std::swap(arr[1], arr.back());
    arr.pop_back();
    heapify_down(arr, 1, arr.size() - 1);
}

int main() {
    std::vector<int> arr = {0, 5, 9, 11, 14, 18, 21, 19, 13, 17, 21};
    insert(arr, 7);
    insert(arr, 15);
    delete_min(arr);

    // Print the resulting array
    for (int i = 1; i < arr.size(); ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}


#include <iostream>
#include <vector>

void heapify_up(std::vector<int>& arr, int i) {
    while (i > 1 && arr[i] > arr[i / 2]) {
        std::swap(arr[i], arr[i / 2]);
        i /= 2;
    }
}

void heapify_down(std::vector<int>& arr, int i, int n) {
    int left = 2 * i;
    int right = 2 * i + 1;
    int largest = i;
    if (left <= n && arr[left] > arr[largest]) {
        largest = left;
    }
    if (right <= n && arr[right] > arr[largest]) {
        largest = right;
    }
    if (largest != i) {
        std::swap(arr[i], arr[largest]);
        heapify_down(arr, largest, n);
    }
}

void insert(std::vector<int>& arr, int key) {
    arr.push_back(key);
    heapify_up(arr, arr.size() - 1);
}

void delete_max(std::vector<int>& arr) {
    std::swap(arr[1], arr.back());
    arr.pop_back();
    heapify_down(arr, 1, arr.size() - 1);
}

int main() {
    // H1
    std::vector<int> h1 = {0, 32, 10, 8, 1, 9, 7, 6};
    insert(h1, 12);

    // H2
    std::vector<int> h2 = {0, 20, 10, 8, 1, 9, 3, 6};
    delete_max(h2);

    // Print the resulting heaps
    std::cout << "H1:\n";
    for (int i = 1; i < h1.size(); ++i) {
        std::cout << h1[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "H2:\n";
    for (int i = 1; i < h2.size(); ++i) {
        std::cout << h2[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}