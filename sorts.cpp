#include "sorts.h"

// реализация сортировки выбором [1]
void selectionSort(int* array, int size) {
    for (int i = 0; i < size - 1; ++i) {
        int min_index = i;
        for (int j = i + 1; j < size; ++j) {
            if (array[j] < array[min_index]) {
                // находим индекс минимального элемента в текущей части массива
                min_index = j; 
            }
        }
        // меняем это значение со значением на первой неотсортированной позиции
        swap(array[i], array[min_index]);
    }
}

// реализация сортировки пузырьком [2]
void bubbleSort(int* array, int size) {
    for (int i = 0; i < size - 1; ++i) {
        for (int j = 0; j < size - i - 1; ++j) {
            if (array[j] > array[j + 1]) {
                // меняем элементы местами, если они стоят в неверном порядке
                swap(array[j], array[j + 1]);
            }
        }
    }
}

// реализация сортировки пузырьком с условием Айверсона 1 [3]
void bubbleSortWithFirstIversonCondition(int* array, int size) {
    int i = 0;
    bool t = true;
    while (t) {
        // если не было ни одного обмена во внутреннем цикле, то массив отсортирован
        t = false;
        for (int j = 0; j < size - i - 1; ++j) {
            if (array[j] > array[j + 1]) {
                swap(array[j], array[j + 1]);
                t = true;
            }
        }
        i = i + 1;
    }
}

// реализация сортировки пузырьком с условием Айверсона 2 [4]
void bubbleSortWithSecondIversonCondition(int* array, int size) {
    int t = size - 1;
    for (int i = 0; i < size - 1; ++i) {
        int bound = t;
        t = 0;
        for (int j = 0; j < bound; ++j) {
            if (array[j] > array[j + 1]) {
                swap(array[j], array[j + 1]);
                // запоминаем в какой позиции был последний обмен
                t = j;
            }
        }
        if (t == 0) {
            // значит обменов не было, массив отсортирован
            break;
        }
    }
}


// реализация сортировки простыми вставками [5]
void insertionSort(int* array, int size) {
    for (int i = 1; i < size; ++i) {
        for (int j = i; j > 0 && array[j - 1] > array[j]; --j) {
            // ищем место для текущего элемента в отсортированной части массива
            swap(array[j], array[j - 1]);
        }
    }
}

// бинарный поиск, вспомогательная функция для сортировки бинарными вставками
int binSearch(int* nums, int key, int l, int r) {
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

// реализация сортировки бинарными вставками [6]
void binaryInsertionSort(int* array, int size) {
    for (int i = 1; i < size; ++i) {
        int j = i - 1;
        // ищем бинпоиском место для вставки текущего элемента в отсортированную часть массива
        int k = binSearch(array, array[i], 0, j);
        for (int m = j; m >= k; --m) {
            swap(array[m], array[m + 1]);
        }
    }
}

// функция нахождения максимального числа в массивe, вспомогательная функция для устойчивой сортировки подсчетом [7]
int findMax(int *array, int size) {
    int maxi = array[0];
    for (int i = 1; i < size; ++i) {
        maxi = max(maxi, array[i]);
    }
    return maxi;
}

// реализация устойчивой сортировки подсчетом [7]
void countingSort(int* array, int size) {
    // находим максимальное число
    int k = findMax(array, size);
    int* sorted = new int[k + 1];
    for (int i = 0; i < k + 1; ++i) {
        sorted[i] = 0;
    }
    for (int i = 0; i < size; ++i) {
        // +1 к количеству встретившегося числа
        ++sorted[array[i]];
    }
    int index = 0;
    for (int i = 0; i < k + 1; ++i) {
        for (int j = 0; j < sorted[i]; ++j) {
            array[index] = i;
            ++index;
        }
    }
    delete[] sorted;
}

// реализация цифровой сортировки [8]
void radixSort(int* array, int size) {
    int base = 256; // основание
    vector<int> b[base];
    for (int i = 0; i < size; ++i) {
        // проходимся по последнему разряду (основание 256)
        b[array[i] % base].push_back(array[i]);
    }
    int index = 0;
    for (int i = 0; i < base; ++i) {
        for (size_t j = 0; j < b[i].size(); ++j) {
            array[index] = b[i][j];
            ++index;
        }
        b[i].clear();
    }
    for (int i = 0; i < size; ++i) {
        // проходимся по предпоследнему разряду (основание 256)
        b[(array[i] / base) % base].push_back(array[i]);
    }
    index = 0;
    for (int i = 0; i < base; ++i) {
        for (size_t j = 0; j < b[i].size(); ++j) {
            array[index] = b[i][j];
            ++index;
        }
        b[i].clear();
    }
}

// истинная сортировка слиянием, вспомогательная функция для функции-оберкти сортировки слиянием [9]
void realMergeSort(int *array, int l, int r) {
    // если элемент тот же, то он уже отсортирован
    if (l == r) {
        return;
    }
    int mid = (l + r) / 2;
    // далее рекурсивно сортируем каждую половину массива
    realMergeSort(array, l, mid);
    realMergeSort(array, mid + 1, r);
    int first = l;  // начало первой половины
    int second = mid + 1; // начало второй половины
    int *sorted = new int[r - l + 1];
    // делаем слияние (merge), записываем результат во вспомогательный массив
    for (int i = 0; i < r - l + 1; ++i) {
        if ((second > r) || ((first <= mid) && (array[first] < array[second]))) {
            sorted[i] = array[first];
            ++first;
        } else {
            sorted[i] = array[second];
            ++second;
        }
    }
    for (int i = 0; i < r - l + 1; ++i) {
        array[i + l] = sorted[i];
    }
    delete[] sorted;
}

// реализация сортировки слиянием [9] (функция-обертка)
void mergeSort(int* array, int size) {
    realMergeSort(array, 0, size - 1);
}

// реализация быстрой сортировки с первым опорным элементом [10]
void quickSort(int* array, int size) {
    int l = 0;
    int r = size - 1;
    int mid = array[0]; // первый опорный элемент
    while (l <= r) {
        while (array[l] < mid) {
            ++l;
        }
        while (array[r] > mid) {
            --r;
        }
        if (l <= r) {
            swap(array[l], array[r]);
            ++l;
            --r;
        }
    }
    if (r > 0) {
        quickSort(array, r + 1);
    }
    if (l < size) {
        quickSort(&array[l], size - l);
    }
}

// реализация быстрой сортировки со средним опорным элементом [10.2]
// это я от себя добавила, в задании не просили реализовывать
// я решила сделать для показательности
void quickSortMid(int* array, int size) {
    int l = 0;
    int r = size - 1;
    int mid = array[(r + l) / 2]; // средний опорный элемент
    while (l <= r) {
        while (array[l] < mid) {
            ++l;
        }
        while (array[r] > mid) {
            --r;
        }
        if (l <= r) {
            swap(array[l], array[r]);
            ++l;
            --r;
        }
    }
    if (r > 0) {
        quickSortMid(array, r + 1);
    }
    if (l < size) {
        quickSortMid(&array[l], size - l);
    }
}

// вспомогательная функция для пирамидальной сортировки [11]
void heapify(int i, int* heap, int size) {
    // упорядочиваем кучу
    int left_child = 2 * i + 1;
    int right_child = 2 * i + 2;
    int largest_child = i;
    if (left_child < size && heap[left_child] > heap[largest_child]) {
        largest_child = left_child;
    }
    if (right_child < size && heap[right_child] > heap[largest_child]) {
        largest_child = right_child;
    }
    if (largest_child != i) {
        swap(heap[i], heap[largest_child]);
        heapify(largest_child, heap, size);
    }
}

// реализация пирамидальной сортировки [11]
void heapSort(int* array, int size) {
    for (int i = size / 2; i >= 0; --i) {
        heapify(i, array, size);
    }
    for (int i = size - 1; i >= 0; --i) {
        swap(array[i], array[0]);
        heapify(0, array, i);
    }
}

// реализация сортировки Шелла (последовательность Циура) [12]
void shellSortCiur(int* array, int size) {
    // известны интервалы, используем их
    int intervals[9] = {1750, 701, 301, 132, 57, 23, 10, 4, 1};
    for (auto d : intervals) {
        for (int i = d; i < size; ++i){
            for (int j = i - d; j >= 0 && array[j] > array[j + d]; j -= d) {
                swap(array[j], array[j + d]);
            }
        }
    }
}

// реализация сортировки Шелла (последовательность Шелла) [13]
void shellSortShell(int* array, int size) {
    // начинаем с большого интервала между элементами, затем потихоньку уменьшаем его
    for (int d = size / 2; d > 0; d /= 2) {
        for (int i = d; i < size; ++i){
            for (int j = i - d; j >= 0 && array[j] > array[j + d]; j -= d) {
                swap(array[j], array[j + d]);
            }
        }
    }
}
