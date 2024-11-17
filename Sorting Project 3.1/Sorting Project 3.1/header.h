#ifndef HEADER_H
#define HEADER_H

void heapify(int arr[], int n, int i);
void heapSort(int arr[], int n);
void fillArray(int arr[], int size);
void measureSortTime(void (*sortFunc)(int[], int), int arr[], int size);
void mergeSort(int arr[], int left, int right);
void merge(int arr[], int left, int mid, int right);//these 2 lines declare the Merge Sort Function
void measureMergeSortTime(void (*sortFunc)(int[], int, int), int arr[], int left, int right);
#endif // HEADER_H





//checks to see if HEADER has been used
 //includes HEADER 

 //declares function , arr = array , n = size
//declares heapSort function, this sorts the array of size (n)
//declares fillArray, fills an array of size (n) with random values (rand)
 // declares measureSortTIme , which measures the time taken by a sorting function (sortFunc) to sort an array of size (n), sortFunc is a pointer to a function

 //HEADER_H This line ends function from the undefined ifndef HEADER_H