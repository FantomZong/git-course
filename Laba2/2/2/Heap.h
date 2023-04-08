#pragma once
#include<climits>


int Parent(int i);

int Left(int i);

int Right(int i);

void MaxHeapify(int* A, int i, int);

void MinHeapify(int* A, int i);

void BildMaxHeap(int* A, int size);

void BildMinHeap(int* A);

void HeapSort(int* A, int size, bool);


//черги


int HeapMaximum(int* A);

int Minimum(int* A);

int HeapExtractMax(int* A);

int ExtractMin(int* A);

void HeapIncreaseKey(int* A, int i, int key);

void HeapDecreaseKey(int* A, int i, int key);

void MaxHeapInsert(int* A, int key);

void MinHeapInsert(int* A, int key);

