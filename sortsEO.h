#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::max;
using std::swap;
using std::vector;

int selectionSortEO(int* array, int size);
int bubbleSortEO(int* array, int size);
int bubbleSortWithFirstIversonConditionEO(int* array, int size);
int bubbleSortWithSecondIversonConditionEO(int* array, int size);
int insertionSortEO(int* array, int size);
int binSearchEO(int* nums, int key, int l, int r);
int binElOpSearchEO(int* nums, int key, int l, int r, int eo);
int binaryInsertionSortEO(int* array, int size);
int findMaxEO(int *array, int size);
int countingSortEO(int* array, int size);
int radixSortEO(int* array, int size);
int realMergeSortEO(int *array, int l, int r, int eo);
int mergeSortEO(int* array, int size);
int quickSortEO(int* array, int size, int elop = 0);
int quickSortMidEO(int* array, int size, int elop = 0);
int heapifyEO(int i, int* heap, int size, int elop);
int heapSortEO(int* array, int size);
int shellSortCiurEO(int* array, int size);
int shellSortShellEO(int* array, int size);
