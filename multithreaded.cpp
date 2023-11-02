#include <iostream>
#include <vector>
#include <thread>

void merge(std::vector<int>& arr, int left, int middle, int right) {
    // Merge function (same as in the basic Merge Sort)
    // ...
}

void mergeSortParallel(std::vector<int>& arr, int left, int right) {
    if (left < right) {
        int middle = left + (right - left) / 2;
        
        std::thread leftThread(mergeSortParallel, std::ref(arr), left, middle);
        std::thread rightThread(mergeSortParallel, std::ref(arr), middle + 1, right);

        leftThread.join();
        rightThread.join();

        merge(arr, left, middle, right);
    }
}

int main() {
    std::vector<int> myVec = {12, 11, 13, 5, 6, 7};

    mergeSortParallel(myVec, 0, myVec.size() - 1);

    std::cout << "Sorted array: ";
    for (int num : myVec) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}

