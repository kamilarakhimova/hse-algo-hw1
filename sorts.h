#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::max;
using std::swap;
using std::vector;

void selectionSort(int* array, int size);
void bubbleSort(int* array, int size);
void bubbleSortWithFirstIversonCondition(int* array, int size);
void bubbleSortWithSecondIversonCondition(int* array, int size);
void insertionSort(int* array, int size);
int binSearch(int* nums, int key, int l, int r);
void binaryInsertionSort(int* array, int size);
int findMax(int *array, int size);
void countingSort(int* array, int size);
void radixSort(int* array, int size);
void realMergeSort(int *array, int l, int r);
void mergeSort(int* array, int size);
void quickSort(int* array, int size);
void quickSortMid(int* array, int size);
void heapify(int i, int* heap, int size);
void heapSort(int* array, int size);
void shellSortCiur(int* array, int size);
void shellSortShell(int* array, int size);
