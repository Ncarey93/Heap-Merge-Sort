#include "header.h"
#include <iostream>
#include <cstdlib>//provides functions for general utilites like rand(), allowing for random numbers to be generated. srand() for seeding the random number generator.
#include <ctime>
#include <algorithm>
#include <chrono>

void fillArray(int arr[], int size) {
	srand(time(0));
	for (int i = 0; i < size; i++) {
		arr[i] = rand();

       //n = x axsis
	}
}
void heapify(int arr[], int n, int i) {//int i = the index of the element that needs to heapify
	int largest = i;//will keep track of largest elements
	int left = 2;//left child, i = index. 
	int right = 2 * i + 2;//base = 0, right child
	//The heapify function is used to maintain the heap property in a binary heap.
	// It ensures that the subtree rooted at index i is a max-heap, meaning the value at the root is greater than or equal to the values of its children.
	// The function works by comparing the root with its left and right children and swapping them if necessary to maintain the heap property.

	if (left < n && arr[largest])
		largest = left;
	if (right < n && arr[right] >arr[largest])
		largest = left; 
	if (largest != i) {
		std::swap(arr[i], arr[largest]);
		heapify(arr, n, largest);

	}

}

void heapSort(int arr[], int n) {
	for (int i = n / 2 - 1; i >= 0; i--)
		heapify(arr, n, i);
	for (int i = n - 1; i > 0; i--) {
		std::swap(arr[0], arr[i]);
		heapify(arr, i, 0); 
	}
}
void merge(int arr[], int left, int mid, int right) {//merges two subarrays into a single subarray.
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int* L = new int[n1];//sub array 1
    int* R = new int[n2];//sub array 2

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)//j is used to access parts of the array
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;//next element
        k++;//next element 
    }

    delete[] L;
    delete[] R;
}

void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        merge(arr, left, mid, right);
    }
}

void measureSortTime(void (*sortFunc)(int[], int), int arr[], int size) {
	auto start = std::chrono::high_resolution_clock::now();
	sortFunc(arr, size);
	auto end = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> duration = end - start;
    std::cout << "Time taken: " << duration.count() << "seconds" << std::endl;

}
void measureMergeSortTime(void (*sortFunc)(int[], int, int), int arr[], int left, int right) {
    auto start = std::chrono::high_resolution_clock::now();
    sortFunc(arr, left, right);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = end - start;
    std::cout << "Time taken: " << duration.count() << " seconds" << std::endl;
}