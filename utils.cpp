#include "utils.h"

// генератор массива со случайными значениями от 0 до 5
void littleGenerate(int* array, int size) {
    // устанавливаем начальную точку генерирования последовательности
    srand(time(NULL));
    // задаём диапазон
    int minn = 0;
    int maxx = 5;
    for (int i = 0; i < size; ++i) {
        // теперь получаем рандомные чиселки в необходимом диапазоне
        array[i] = minn + rand() % (maxx - minn + 1);
    }
}

// генератор массива со случайными значениями от 0 до 4000
void hugeGenerate(int* array, int size) {
    // устанавливаем начальную точку генерирования последовательности
    srand(time(NULL));
    // задаём диапазон
    int minn = 0;
    int maxx = 4000;
    for (int i = 0; i < size; ++i) {
        // теперь получаем рандомные чиселки в необходимом диапазоне
        array[i] = minn + rand() % (maxx - minn + 1);
    }
}

// генератор "почти" отсортированного массива
void almostSortedGenerate(int* array, int size) {
    for (int i = 0; i < size; ++i) {
        array[i] = i + 1;
    }
    for (int i = 0; i < size; ++i) {
        if (i != 0 && i % 30 == 0) {
            swap(array[i], array[i - 15]);
        }
    }
}

// генератор массива с числами, отсортированными по убыванию
void reverseSortedGenerate(int* array, int size) {
    for (int i = size; i >= 1; --i) {
        array[i - 1] = i;
    }
}

// функция проверки корректности сортировки массива
bool checker(int* array, int size) {
    bool flag = true;
    for (int i = 0; i < size - 1; ++i) {
        if (array[i] > array[i + 1]) {
            flag = false;
            break;
        }
    }
    return flag;
}


// функция копирования эталонного массива в рабочий
void copyArray(int* original, int* fake, int size) {
    for (int i = 0; i < size; ++i) {
        fake[i] = original[i];
    }
}
