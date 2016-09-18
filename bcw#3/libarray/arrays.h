#include <stdio.h>

#ifndef ARRAYS
#define ARRAYS

void arrayAbs(int array[], int size);
void arrayCopy(int destination[], int source[], int size);
void arrayExchange(int array[], int len);
void arrayIncrement(int array[], int size, int increment);
void arrayPrintReversed(int array[], int size);
void arrayPrintReversedFile(FILE *out, int array[], int size);
void arrayPrint(int array[], int size);
void arrayPrintFile(FILE *out, int array[], int size);
void arrayReverse(int array[], int size);
void arrayShiftLeft(int array[], int size);
void arrayShiftRight(int array[], int size);
void arraySort(int array[], int size);
void arrayZeroFill(int array[], int size);
void sliceReverse(int array[], int lo, int hi);
void sliceShiftLeft(int array[], int start, int end);
void sliceShiftRight(int array[], int start, int end);
void arrayMerge(int target[], int src1[], int len1, int src2[], int len2);
void arrayShift(int array[], int size, int shift);
int arrayMax(int array[], int size);
int arrayMin(int array[], int size);
int arrayScan(FILE *in, int array[], int limit);
int arraySearch(int array[], int size, int needle);
int arraySum(int array[], int size);
int arrayUnique(int array[], int size);

#endif
