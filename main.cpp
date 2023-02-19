#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <fstream>
#include <vector>
#include <chrono>
#include <string>
#include "sorts.h"
#include "sortsEO.h"
#include "utils.h"

using std::cin;
using std::cout;
using std::ios_base;
using std::max;
using std::swap;
using std::vector;
using std::string;
using std::chrono::duration_cast;
using std::chrono::high_resolution_clock;
using std::chrono::nanoseconds;

int64_t midTime(int* array, int size, int choice);
int64_t sortTime(int* array, int size, int choice);
int sortElOp(int* array, int size, int choice);
string sortName(int choice);
void printArrayToFile(int* array, int size);

int main() {
    const int max_size = 4100;

    // генерируем 4 эталонных массива
    int* array1 = new int[max_size];
    littleGenerate(array1, max_size);
    int* array2 = new int[max_size];
    hugeGenerate(array2, max_size);
    int* array3 = new int[max_size];
    almostSortedGenerate(array3, max_size);
    int* array4 = new int[max_size];
    reverseSortedGenerate(array4, max_size);

    // тут идёт первая часть таблиц и графиков (13 (+1) * 4)
    for (int i = 1; i <= 14; ++i) {
        // для каждого вида сортировки
        std::ofstream myfile;
        string folder = "TablesForGraphs/";
        string name = sortName(i);
        int64_t time;
        int elop;
        cout << "Прогресс: " << name << " " << i << "/13 (+1)" << "\n";
        // сначала для массивов размера 50 - 300 время
        myfile.open(folder + name + " 1.csv");
        for (int j = 50; j <= 300; j += 50) {
            // для каждого размера массива с шагом 50
            time = midTime(array1, j, i); // усредненное время сортировки
            myfile << j << ';' << time << ';';
            time = midTime(array2, j, i); // усредненное время сортировки
            myfile << time << ';';
            time = midTime(array3, j, i); // усредненное время сортировки
            myfile << time << ';';
            time = midTime(array4, j, i); // усредненное время сортировки
            myfile << time << '\n';
        }
        myfile.close();
        // далее аналогично для массивов размера 100 - 4100 время
        myfile.open(folder + name + " 2.csv");
        for (int j = 100; j <= 4100; j += 100) {
            // для каждого размера массива с шагом 100
            time = midTime(array1, j, i); // усредненное время сортировки
            myfile << j << ';' << time << ';';
            time = midTime(array2, j, i); // усредненное время сортировки
            myfile << time << ';';
            time = midTime(array3, j, i); // усредненное время сортировки
            myfile << time << ';';
            time = midTime(array4, j, i); // усредненное время сортировки
            myfile << time << '\n';
        }
        myfile.close();
        // потом для массивов размера 50 - 300 количество эл. оп.
        myfile.open(folder + name + " 3.csv");
        for (int j = 50; j <= 300; j += 50) {
            // для каждого размера массива с шагом 50
            elop = sortElOp(array1, j, i); // количество элементарных операций
            myfile << j << ';' << elop << ';';
            elop = sortElOp(array2, j, i); // количество элементарных операций
            myfile << elop << ';';
            elop = sortElOp(array3, j, i); // количество элементарных операций
            myfile << elop << ';';
            elop = sortElOp(array4, j, i); // количество элементарных операций
            myfile << elop << '\n';
        }
        myfile.close();
        // далее аналогично для массивов размера 100 - 4100 кол-во эл. оп.
        myfile.open(folder + name + " 4.csv");
        for (int j = 100; j <= 4100; j += 100) {
            // для каждого размера массива с шагом 100
            elop = sortElOp(array1, j, i); // количество элементарных операций
            myfile << j << ';' << elop << ';';
            elop = sortElOp(array2, j, i); // количество элементарных операций
            myfile << elop << ';';
            elop = sortElOp(array3, j, i); // количество элементарных операций
            myfile << elop << ';';
            elop = sortElOp(array4, j, i); // количество элементарных операций
            myfile << elop << '\n';
        }
        myfile.close();
    }
  
    // затем идёт вторая часть табличек и графиков (4 * 4)
    
    delete[] array1;
    delete[] array2;
    delete[] array3;
    delete[] array4;
    return 0;
}

// функция, возвращающая усреднённое время сортировки с 10 испытаний
int64_t midTime(int* array, int size, int choice) {
    int64_t mtime = sortTime(array, size, choice) + sortTime(array, size, choice);
    mtime += sortTime(array, size, choice) + sortTime(array, size, choice);
    mtime += sortTime(array, size, choice) + sortTime(array, size, choice);
    mtime += sortTime(array, size, choice) + sortTime(array, size, choice);
    mtime += sortTime(array, size, choice) + sortTime(array, size, choice);
    mtime /= 10;
    return mtime;
}

// функция, возвращающая время сортировки массива
int64_t sortTime(int* array, int size, int choice) {
    int time;
    int* array_copy = new int[size];
    copyArray(array, array_copy, size);
    auto start = high_resolution_clock::now();
    switch (choice) {
        case 1:
            selectionSort(array_copy, size);
            break;
        case 2:
            bubbleSort(array_copy, size);
            break;
        case 3:
            bubbleSortWithFirstIversonCondition(array_copy, size);
            break;
        case 4:
            bubbleSortWithSecondIversonCondition(array_copy, size);
            break;
        case 5:
            insertionSort(array_copy, size);
            break;
        case 6:
            binaryInsertionSort(array_copy, size);
            break;
        case 7:
            countingSort(array_copy, size);
            break;
        case 8:
            radixSort(array_copy, size);
            break;
        case 9:
            mergeSort(array_copy, size);
            break;
        case 10:
            quickSort(array_copy, size);
            break;
        case 11:
            quickSortMid(array_copy, size);
            break;
        case 12:
            heapSort(array_copy, size);
            break;
        case 13:
            shellSortCiur(array_copy, size);
            break;
        case 14:
            shellSortShell(array_copy, size);
            break;
        default:
            break;
    }
    auto elapsed = high_resolution_clock::now() - start;
    int64_t elapsed_ms = duration_cast<nanoseconds>(elapsed).count();
    // если массив после работы оказался неотсортирован
    if (checker(array_copy, size) == 0) {
        cout << "Programm is tired and works incorrectly :("; 
        return 0;
    }
    delete[] array_copy;
    return elapsed_ms;
}

// функция, возвращающая количество элементарных операций при сортировке массива
int sortElOp(int* array, int size, int choice) {
    int elop;
    int* array_copy = new int[size];
    copyArray(array, array_copy, size);
    switch (choice) {
        case 1:
            elop = selectionSortEO(array_copy, size);
            break;
        case 2:
            elop = bubbleSortEO(array_copy, size);
            break;
        case 3:
            elop = bubbleSortWithFirstIversonConditionEO(array_copy, size);
            break;
        case 4:
            elop = bubbleSortWithSecondIversonConditionEO(array_copy, size);
            break;
        case 5:
            elop = insertionSortEO(array_copy, size);
            break;
        case 6:
            elop = binaryInsertionSortEO(array_copy, size);
            break;
        case 7:
            elop = countingSortEO(array_copy, size);
            break;
        case 8:
            elop = radixSortEO(array_copy, size);
            break;
        case 9:
            elop = mergeSortEO(array_copy, size);
            break;
        case 10:
            elop = quickSortEO(array_copy, size);
            break;
        case 11:
            elop = quickSortMidEO(array_copy, size);
            break;
        case 12:
            elop = heapSortEO(array_copy, size);
            break;
        case 13:
            elop = shellSortCiurEO(array_copy, size);
            break;
        case 14:
            elop = shellSortShellEO(array_copy, size);
            break;
        default:
            break;
    }
    delete[] array_copy;
    return elop;
}


string sortName(int choice) {
    string name;
    switch (choice) {
        case 1:
            name = "Selection Sort";
            break;
        case 2:
            name = "Bubble Sort";
            break;
        case 3:
            name = "Bubble Sort Iverson 1";
            break;
        case 4:
            name = "Bubble Sort Iverson 2";
            break;
        case 5:
            name = "Insertion Sort";
            break;
        case 6:
            name = "Binary Insertion Sort";
            break;
        case 7:
            name = "Counting Sort";
            break;
        case 8:
            name = "Radix Sort";
            break;
        case 9:
            name = "Merge Sort";
            break;
        case 10:
            name = "Quick Sort (first support)";
            break;
        case 11:
            name = "Quick Sort (middle support)";
            break;
        case 12:
            name = "Heap Sort";
            break;
        case 13:
            name = "Shell Sort (Ciur sequence)";
            break;
        case 14:
            name = "Shell Sort (Shell sequence)";
            break;
        default:
            break;
    }
    return name;
}

void printArrayToFile(int* array, int size) {
    std::ofstream output;          // поток для записи
    output.open("input.txt");     // открываем файл для записи
    for (int i = 0; i < size; ++i) {
        output << array[i] << ' ';
    }
    output.close();
}
