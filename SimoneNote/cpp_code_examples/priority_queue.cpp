#include <iostream>
#include <vector>

bool is_priority_queue(const std::vector<int>& arr) {
    int n = arr.size() - 1; // Exclude the unused element at index 0
    for (int i = 1; i <= n / 2; ++i) {
        int left_child = 2 * i;
        int right_child = 2 * i + 1;
        if (left_child <= n && arr[i] < arr[left_child]) {
            std::cout << "Failed at index " << i << " with left child " << left_child << std::endl;
            return false;
        }
        if (right_child <= n && arr[i] < arr[right_child]) {
            std::cout << "Failed at index " << i << " with right child " << right_child << std::endl;
            return false;
        }
    }
    return true;
}

int main() {
    std::vector<int> arr = {0, 17, 21, 23, 44, 32, 65, 38, 56, 46, 69, 33, 77, 67, 56, 39, 61, 60, 62, 50, 71};

    if (is_priority_queue(arr)) {
        std::cout << "The array represents a priority queue." << std::endl;
    } else {
        std::cout << "The array does not represent a priority queue." << std::endl;
    }

    return 0;
}