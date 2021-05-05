#include <iostream>
using namespace std;  
int partition (int arr[], int low, int high)  
{  
    int pivot_id = low + (high - low) / 2; 
    int pivot_value = arr[pivot_id];
    swap(arr[pivot_id],arr[high]);
    int i = low;  
    for (int j = low; j <= high - 1; j++)  
    {  
        if (arr[j] < pivot_value)  
        {  
            swap(arr[i], arr[j]);  
            i ++;
        }       
    }  
    swap(arr[i], arr[high]);  
    return i;  
}  
void quickSort(int arr[], int low, int high)  
{  
    if (low < high)  
    {  
        int pi = partition(arr, low, high);  

        quickSort(arr, low, pi - 1);  
        quickSort(arr, pi + 1, high);  
    }  
}  
int main()  
{  
    int arr[] = {10, 7, 8, 9, 1, 5};  
    int n = sizeof(arr) / sizeof(arr[0]);  
    quickSort(arr, 0, n - 1);  
    int i;  
    for (i = 0; i < n; i++)  
    {
        cout << arr[i] << " ";  
    }
    cout << endl;
    return 0;  
}  