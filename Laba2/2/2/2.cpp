#include <iostream>
#include<climits>
#include"Heap.h"
using namespace std;

int main()
{
    int n;
    cout << "Enter array size : ";
    cin >> n;

    int* A = new int[n + 1];

    A[0] = n * 10000;
    cout << "\nEnter heap sise : ";
    cin >> n;
    A[0] += n;
    for (int i = 1; i <= n; i++)
    {
        cin >> A[i];
    }
    // cout << "Build min heap : \n";
    // BildMinHeap(A);
    // for (int i = 1; i <= n; i++)
    // {
    //     cout << A[i] << " ";
    // }
    cout << "\nBuild max heap : \n";
    BildMaxHeap(A, n);
    //HeapSort(A, n, 1);
    //MaxHeapify(A, 2, n);
    // MinHeapify(A, 2);
    // BildMinHeap(A);
    for (int i = 1; i <= n; i++)
    {
        cout << A[i] << " ";
    }
    cout << "\nHeapMaximum : " << HeapMaximum(A);
    cout << "\nExtractMAX : " << HeapExtractMax(A) << endl;
    for (int i = 1; i <= n; i++)
    {
        cout << A[i] << " ";
    }
    cout << "\nHeapIncreaseKey ";
    HeapIncreaseKey(A, 2, 100);
    for (int i = 1; i <= n; i++)
    {
        cout << A[i] << " ";
    }
    cout << "\nMaxHeapInsert : ";
    MaxHeapInsert(A, 2);

    for (int i = 1; i <= n; i++)
    {
        cout << A[i] << " ";
    }

    //cout << "\nHeapSort : \n";
    //HeapSort(A, n, 1);
    //for (int i = 1; i <= n; i++)
    //{
    //    cout << A[i] << " ";
    //}


 //----------------------------------------------------------------
    BildMinHeap(A);
    cout << "\nBild min heap : \n";
    for (int i = 1; i <= n; i++)
    {
        cout << A[i] << " ";
    }

    cout << "\nHeapMinimum : " << Minimum(A);
    cout << "\nExtractMin : " << ExtractMin(A) << endl;
    for (int i = 1; i <= n; i++)
    {
        cout << A[i] << " ";
    }
    cout << "\nHeapDecreaseKey ";
    HeapDecreaseKey(A, 2, 1);
    for (int i = 1; i <= n; i++)
    {
        cout << A[i] << " ";
    }
    cout << "\nMinHeapInsert : ";
    MinHeapInsert(A, 2);

    for (int i = 1; i <= n; i++)
    {
        cout << A[i] << " ";
    }
}
