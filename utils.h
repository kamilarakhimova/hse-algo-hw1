#include <iostream>
#include <stdlib.h>
#include <time.h>

using std::swap;
using std::string;

void littleGenerate(int* array, int size);
void hugeGenerate(int* array, int size);
void almostSortedGenerate(int* array, int size);
void reverseSortedGenerate(int* array, int size);
bool checker(int* array, int size);
void copyArray(int* original, int* fake, int size);
