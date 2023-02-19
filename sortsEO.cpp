/*

Далее в каждой функции:
@param array - массив чисел, которые надо отсортировать
@param size - размер массива чисел

Переменная elop = счетчик количества элементарных операций.

Также по умолчанию считается, что функция swap реализует 6 элементарных операций.

*/

#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::max;
using std::swap;
using std::vector;

// реализация сортировки выбором [1]
int selectionSortEO(int* array, int size) {
    int elop = 0;
    for (int i = 0; i < size - 1; ++i) {
        elop += 6;
        int min_index = i;
        elop += 2;
        for (int j = i + 1; j < size; ++j) {
            elop += 7;
            if (array[j] < array[min_index]) {
                min_index = j;
                elop += 2;
            }
            elop += 5;
        }
        swap(array[i], array[min_index]);
        elop += 6;
    }
    return elop;
}

// реализация сортировки пузырьком [2]
int bubbleSortEO(int* array, int size) {
    int elop = 0;
    for (int i = 0; i < size - 1; ++i) {
        elop += 6;
        for (int j = 0; j < size - i - 1; ++j) {
            elop += 8;
            if (array[j] > array[j + 1]) {
                swap(array[j], array[j + 1]);
                elop += 6;
            }
            elop += 5;
        }
    }
    return elop;
}

// реализация сортировки пузырьком с условием Айверсона 1 [3]
int bubbleSortWithFirstIversonConditionEO(int* array, int size) {
    int elop = 0;
    int i = 0;
    bool t = true;
    elop += 2;
    while (t) {
        elop += 1;
        t = false;
        elop += 1;
        for (int j = 0; j < size - i - 1; ++j) {
            elop += 8;
            if (array[j] > array[j + 1]) {
                swap(array[j], array[j + 1]);
                elop += 6;
                t = true;
                elop += 1;
            }
            elop += 5;
        }
        i = i + 1;
        elop += 2;
    }
    return elop;
}

// реализация сортировки пузырьком с условием Айверсона 2 [4]
int bubbleSortWithSecondIversonConditionEO(int* array, int size) {
    int elop = 0;
    int t = size - 1;
    elop += 3;
    for (int i = 0; i < size - 1; ++i) {
        elop += 6;
        int bound = t;
        t = 0;
        elop += 3;
        for (int j = 0; j < bound; ++j) {
            elop += 5;
            if (array[j] > array[j + 1]) {
                swap(array[j], array[j + 1]);
                elop += 6;
                t = j;
                elop += 2;
            }
            elop += 5;
        }
        elop += 2;
        if (t == 0) {
            break;
        }
    }
    return elop;
}

// реализация сортировки простыми вставками [5]
int insertionSortEO(int* array, int size) {
    int elop = 0;
    for (int i = 1; i < size; ++i) {
        elop += 5;
        for (int j = i; j > 0 && array[j - 1] > array[j]; --j) {
            elop += 11;
            swap(array[j], array[j - 1]);
            elop += 6;
        }
    }
    return elop;
}

// бинарный поиск, вспомогательная функция для сортировки бинарными вставками [6]
int binSearchEO(int* nums, int key, int l, int r) {
    int mid;
    while (l < r) {
        mid = (l + (r - l) / 2);
        if (key == nums[mid]) {
            return mid + 1;
        }
        if (key > nums[mid]) {
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    if (key > nums[l]) {
        return l + 1;
    }
    return l;
}

// бинарный поиск, вспомогательная функция для подсчета количества элементарных операций при сортировки бинарными вставками [6]
int binElOpSearchEO(int* nums, int key, int l, int r, int eo) {
    int mid;
    while (l < r) {
        eo += 3;
        mid = (l + (r - l) / 2);
        eo += 7;
        if (key == nums[mid]) {
            eo += 2;
            return eo;
        }
        eo += 4;
        if (key > nums[mid]) {
            l = mid + 1;
        } else {
            r = mid - 1;
        }
        eo += 4;
        eo += 3;
    }
    eo += 4;
    if (key > nums[l]) {
        eo += 2;
        return eo;
    }
    return eo + 1;
}

// реализация сортировки бинарными вставками [6]
int binaryInsertionSortEO(int* array, int size) {
    int elop = 0;
    for (int i = 1; i < size; ++i) {
        elop += 5;
        int j = i - 1;
        elop += 3;
        int k = binSearchEO(array, array[i], 0, j);
        int elop = binElOpSearchEO(array, array[i], 0, j, elop);
        for (int m = j; m >= k; --m) {
            elop += 6;
            swap(array[m], array[m + 1]);
            elop += 6;
        }
    }
    return elop;
}

// функция нахождения максимального числа в массивe, вспомогательная функция для устойчивой сортировки подсчетом [7]
int findMaxEO(int *array, int size) {
    int maxi = array[0];
    for (int i = 1; i < size; ++i) {
        maxi = max(maxi, array[i]);
    }
    return maxi;
}

// реализация устойчивой сортировки подсчетом [7]
int countingSortEO(int* array, int size) {
    int elop = 0;
    int k = findMaxEO(array, size);
    elop += (size - 1) * 10 + 3;
    int* sorted = new int[k + 1];
    elop += 2;
    for (int i = 0; i < k + 1; ++i) {
        elop += 6;
        sorted[i] = 0;
        elop += 2;
    }
    for (int i = 0; i < size; ++i) {
        elop += 5;
        ++sorted[array[i]];
        elop += 5;
    }
    int index = 0;
    elop += 1;
    for (int i = 0; i < k + 1; ++i) {
        elop += 6;
        for (int j = 0; j < sorted[i]; ++j) {
            elop += 6;
            array[index] = i;
            elop += 3;
            ++index;
            elop += 3;
        }
    }
    delete[] sorted;
    elop += k + 1;
    return elop;
}

// реализация цифровой сортировки [8]
int radixSortEO(int* array, int size) {
    int elop = 0;
    int base = 256; // основание
    elop += 1;
    vector<int> b[base];
    elop += base;
    for (int i = 0; i < size; ++i) {
        elop += 6;
        // проходимся по последнему разряду (основание 256)
        b[array[i] % base].push_back(array[i]);
        elop += 8;
    }
    int index = 0;
    elop += 1;
    for (int i = 0; i < base; ++i) {
        elop += 6;
        for (size_t j = 0; j < b[i].size(); ++j) {
            elop += 8;
            array[index] = b[i][j];
            elop += 6;
            ++index;
            elop += 3;
        }
        elop += b[i].size();
        b[i].clear();
    }
    for (int i = 0; i < size; ++i) {
        elop += 6;
        // проходимся по предпоследнему разряду (основание 256)
        b[(array[i] / base) % base].push_back(array[i]);
        elop += 10;
    }
    index = 0;
    elop += 1;
    for (int i = 0; i < base; ++i) {
        elop += 6;
        for (size_t j = 0; j < b[i].size(); ++j) {
            elop += 8;
            array[index] = b[i][j];
            elop += 6;
            ++index;
            elop += 3;
        }
        elop += b[i].size();
        b[i].clear();
    }
    return elop;
}

// истинная сортировка слиянием, вспомогательная функция для функции-обертки сортировки слиянием [9]
int realMergeSortEO(int *array, int l, int r, int eo) {
    if (l == r) {
        eo += 3;
        return eo;
    }
    int mid = (l + r) / 2;
    eo += 5;
    eo = realMergeSortEO(array, l, mid, eo);
    eo = realMergeSortEO(array, mid + 1, r, eo);
    int first = l;
    int second = mid + 1;
    eo += 5;
    int *sorted = new int[r - l + 1];
    eo += r;
    for (int i = 0; i < r - l + 1; ++i) {
        eo += 9;
        if ((second > r) || ((first <= mid) && (array[first] < array[second]))) {
            sorted[i] = array[first];
            ++first;
            eo += 8;
        } else {
            sorted[i] = array[second];
            ++second;
            eo += 8;
        }
        eo += 13;
    }
    for (int i = 0; i < r - l + 1; ++i) {
        eo += 9;
        array[i + l] = sorted[i];
        eo += 7;
    }
    delete[] sorted;
    eo += r;
    return eo;
}

// реализация сортировки слиянием [9] (функция-обертка)
int mergeSortEO(int* array, int size) {
    int elop = 0;
    elop = realMergeSortEO(array, 0, size - 1, elop);
    return elop;
}

// реализация быстрой сортировки с первым опорным элементом [10]
int quickSortEO(int* array, int size, int elop = 0) {
    int l = 0;
    elop += 1;
    int r = size - 1;
    elop += 3;
    int mid = array[0]; // первый опорный элемент
    elop += 2;
    while (l <= r) {
        elop += 3;
        while (array[l] < mid) {
            ++l;
            elop += 7;
        }
        elop += 4;
        while (array[r] > mid) {
            --r;
            elop += 7;
        }
        elop += 4;
        if (l <= r) {
            swap(array[l], array[r]);
            elop += 6;
            ++l;
            --r;
            elop += 6;
        }
        elop += 3;
    }
    elop += 3;
    if (r > 0) {
        elop = quickSortEO(array, r + 1, elop);
    }
    elop += 2;
    if (l < size) {
        elop = quickSortEO(&array[l], size - l, elop);
    }
    elop += 3;
    return elop;
}

// реализация быстрой сортировки со средним опорным элементом [10.2]
// сделала для показательности
int quickSortMidEO(int* array, int size, int elop = 0) {
    int l = 0;
    elop += 1;
    int r = size - 1;
    elop += 3;
    int mid = array[(l + r) / 2]; // средний опорный элемент
    elop += 6;
    while (l <= r) {
        elop += 3;
        while (array[l] < mid) {
            ++l;
            elop += 7;
        }
        elop += 4;
        while (array[r] > mid) {
            --r;
            elop += 7;
        }
        elop += 4;
        if (l <= r) {
            swap(array[l], array[r]);
            elop += 6;
            ++l;
            --r;
            elop += 6;
        }
        elop += 3;
    }
    elop += 3;
    if (r > 0) {
        elop = quickSortMidEO(array, r + 1, elop);
    }
    elop += 2;
    if (l < size) {
        elop = quickSortMidEO(&array[l], size - l, elop);
    }
    elop += 3;
    return elop;
}

// вспомогательная функция для пирамидальной сортировки [11]
int heapifyEO(int i, int* heap, int size, int elop) {
    int left_child = 2 * i + 1;
    elop += 4;
    int right_child = 2 * i + 2;
    elop += 4;
    int largest_child = i;
    elop += 2;
    if (left_child < size && heap[left_child] > heap[largest_child]) {
        largest_child = left_child;
        elop += 2;
    }
    elop += 9;
    if (right_child < size && heap[right_child] > heap[largest_child]) {
        largest_child = right_child;
        elop += 2;
    }
    elop += 9;
    if (largest_child != i) {
        swap(heap[i], heap[largest_child]);
        elop += 6;
        elop = heapifyEO(largest_child, heap, size, elop);
    }
    elop += 3;
    return elop;
}

// реализация пирамидальной сортировки [11]
int heapSortEO(int* array, int size) {
    int elop = 0;
    for (int i = size / 2; i >= 0; --i) {
        elop += 6;
        elop = heapifyEO(i, array, size, elop);
    }
    for (int i = size - 1; i >= 0; --i) {
        elop += 6;
        swap(array[i], array[0]);
        elop += 6;
        elop = heapifyEO(0, array, i, elop);
    }
    return elop;
}

// реализация сортировки Шелла (последовательность Циура) [12]
int shellSortCiurEO(int* array, int size) {
    int elop = 0;
    int intervals[9] = {1750, 701, 301, 132, 57, 23, 10, 4, 1};
    elop += 9;
    for (auto d : intervals) {
        elop += 5;
        for (int i = d; i < size; ++i){
            elop += 6;
            for (int j = i - d; j >= 0 && array[j] > array[j + d]; j -= d) {
                elop += 15;
                swap(array[j], array[j + d]);
                elop += 6;
            }
        }
    }
    return elop;
}

// реализация сортировки Шелла (последовательность Шелла) [13]
int shellSortShellEO(int* array, int size) {
    int elop = 0;
    for (int d = size / 2; d > 0; d /= 2) {
        elop += 6;
        for (int i = d; i < size; ++i){
            elop += 6;
            for (int j = i - d; j >= 0 && array[j] > array[j + d]; j -= d) {
                elop += 15;
                swap(array[j], array[j + d]);
                elop += 6;
            }
        }
    }
    return elop;
}
