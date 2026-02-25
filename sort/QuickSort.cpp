#include "QuickSort.h"

void quickSort(int arr[], int low, int high){
    if (low < high){
        int p = partition (arr,low,high);

        quickSort(arr, low, p-1);
        quickSort(arr, p+1, high);
    }
}

int partition(int arr[], int low, int high){   
    //双指针
    int p = arr[high];
    int s = low; 

    for (int i = low; i < high; i++){
        if(arr[i] < p){
            swap(&arr[i],&arr[s++]);
        }
    }
    swap(&arr[s], &arr[high]);
    return s;
}

void quickSortIterative(int arr[], int l, int h)
{
}
