#include <iostream>
#include "header.h"

int main() {
    const int sizes[] = { 100, 1000, 10000, 100000 };
    for (int size : sizes) {
        int* arr = new int[size];
        fillArray(arr, size);

        std::cout << "Heap Sort for size " << size << ": ";
        measureSortTime(heapSort, arr, size);

        fillArray(arr, size); // Refill the array with random values for the next sort
        std::cout << "Merge Sort for size " << size << ": ";
        measureMergeSortTime(mergeSort, arr, 0, size - 1);

        delete[] arr;
    }
    return 0;
}
// {} curly brackets are used because this is used for initializing the arrays. using () for an array can make things confusing since they are used for other things already.
//I will be using both a Heap Sort and Merge Sort for my examples. I will then compare the two Sort Datasets.
//Mergesort =U(n log(n)) / 0(n log(n)) 0(n log(n)) 0(n)
//Heapsort = U(n log(n)) / " / "  /