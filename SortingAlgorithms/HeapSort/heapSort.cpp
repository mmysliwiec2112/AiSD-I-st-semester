#include <iostream>
#include "heapSort.h"

int parentId(int id)
{
    if (id != 0)
        return id / 2;
}
int leftSoneftSonId(int id)
{
    return 2 * id + 1;
}

int rightSonId(int id)
{
    return 2 * id + 2;
}

void makeHeap(int arr[], int n, int i)
{
    int largest = i;
    int leftSon = leftSoneftSonId(i);
    int rightSon = rightSonId(i); 

    if (leftSon < n && arr[leftSon] > arr[largest])
        largest = leftSon;
 
    if (rightSon < n && arr[rightSon] > arr[largest])
        largest = rightSon;

    if (largest != i) {
        std::swap(arr[i], arr[largest]);

        makeHeap(arr, n, largest);
    }
}
void heapSort(int arr[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
        makeHeap(arr, n, i);

    for (int i = n - 1; i > 0; i--) {
        std::swap(arr[0], arr[i]);

        makeHeap(arr, i, 0);
    }
}

int main()
{
    int arr[] = { 12, 11, 13, 5, 6, 7 };
    int n = sizeof(arr) / sizeof(arr[0]);
 
    heapSort(arr, n);
 
    std::cout << "Sorted array is \n";
    for (int i = 0; i < n; ++i)
        std::cout << arr[i] << " ";
    std::cout << "\n";
}