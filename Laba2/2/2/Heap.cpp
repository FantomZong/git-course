#include "Heap.h"
#include<iostream>

using namespace std;

int Parent(int i)
{
	return i / 2;
}

int Left(int i)
{
	return i * 2;
}

int Right(int i)
{
	return i * 2 + 1;
}

void MaxHeapify(int* A, int i, int heap_size)
{
	int l = Left(i);
	int r = Right(i);
	int largest;
	if (l <= heap_size && A[l] > A[i])
		largest = l;
	else
		largest = i;

	if (r <= heap_size && A[r] > A[largest])
		largest = r;

	if (largest != i) {
		l = A[i];
		A[i] = A[largest];
		A[largest] = l;
		MaxHeapify(A, largest, heap_size);
	}
}

void MinHeapify(int* A, int i)
{
	int l = Left(i);
	int r = Right(i);
	int heap_size = A[0] % 10000;
	int lowest;
	if (l <= heap_size && A[l] < A[i])
		lowest = l;
	else
		lowest = i;

	if (r <= heap_size && A[r] < A[lowest])
		lowest = r;

	if (lowest != i) {
		l = A[i];
		A[i] = A[lowest];
		A[lowest] = l;
		MinHeapify(A, lowest);
	}
}

void BildMaxHeap(int* A, int size)
{
	for (int i = size / 2; i > 0; i--) {
		MaxHeapify(A, i, size);
	}
}

void BildMinHeap(int* A)
{
	for (int i = A[0] / 10000 / 2; i > 0; i--) {
		MinHeapify(A, i);
	}
}

void HeapSort(int* A, int size, bool b)
{
	int num;
	if (b) {
		BildMaxHeap(A, size);
		for (int i = size; i > 1; i--) {
			num = A[1];
			A[1] = A[i];
			A[i] = num;
			MaxHeapify(A, 1, i - 1);
		}

	}
	else {
		BildMinHeap(A);
		for (int i = size; i > 1; i--) {
			num = A[1];
			A[1] = A[i];
			A[i] = num;
			A[0]--;
			MinHeapify(A, 1);
		}
	}
}

int HeapMaximum(int* A)
{
	return A[1];
}

int Minimum(int* A)
{
	return A[1];
}

int HeapExtractMax(int* A)
{
	if (A[0] % 10000 < 1) {
		cout << "Queue is empty!\n";
		return 0;
	}
	int max = A[1];
	A[1] = A[A[0] % 10000];
	A[A[0] % 10000] = 0;
	A[0]--;

	MaxHeapify(A, 1, A[0] % 10000);

	return max;
}

int ExtractMin(int* A)
{
	if (A[0] % 10000 < 1) {
		cout << "Queue is empty!\n";
		return 0;
	}
	int min = A[1];
	A[1] = A[A[0] % 10000];
	A[A[0] % 10000] = 0;
	A[0]--;

	MinHeapify(A, 1);

	return min;
}

void HeapIncreaseKey(int* A, int i, int key)
{
	if (key < A[i]) {
		cout << "Key is lower!\n";
		return;
	}
	A[i] = key;
	int num;
	while (i > 1 && A[Parent(i)] < A[i]) {
		num = A[i];
		A[i] = A[Parent(i)];
		A[Parent(i)] = num;
		i = Parent(i);
	}
}

void HeapDecreaseKey(int* A, int i, int key)
{
	if (key > A[i]) {
		cout << "Key is higher!\n";
		return;
	}
	A[i] = key;
	int num;
	while (i > 1 && A[Parent(i)] > A[i]) {
		num = A[i];
		A[i] = A[Parent(i)];
		A[Parent(i)] = num;
		i = Parent(i);
	}
}

void MaxHeapInsert(int* A, int key)
{
	A[0]++;
	A[A[0] % 10000] = INT_MIN;
	HeapIncreaseKey(A, A[0] % 10000, key);
}

void MinHeapInsert(int* A, int key)
{
	A[0]++;
	A[A[0] % 10000] = INT_MAX;
	HeapDecreaseKey(A, A[0] % 10000, key);
}

