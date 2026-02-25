#include <iostream>
#include <algorithm>
#include "visual.h"
using namespace std;

int partition(int arr[], int l, int r, int n) {
    int pivot = arr[r];
    int i = l - 1;
    for (int j = l; j < r; ++j) {
        // 高亮当前比较的 j 和基准位置 r
        printArray(arr, n, j, r, 200);
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
            // 交换后高亮 i 和 j
            printArray(arr, n, i, j, 200);
        }
    }
    swap(arr[i + 1], arr[r]);
    // 最后交换基准，高亮 i+1 和 r
    printArray(arr, n, i + 1, r, 200);
    return i + 1;
}

// 快速排序递归，带可视化
void quickSort(int arr[], int l, int r, int n) {
    if (l < r) {
        int pi = partition(arr, l, r, n);
        quickSort(arr, l, pi - 1, n);
        quickSort(arr, pi + 1, r, n);
    }
}

int main() {
    int arr[] = { -5, 3, 0, 8, -2, 7, 4, -1, 6, 2 };
    int n = sizeof(arr) / sizeof(arr[0]);

    
    stepMode = true; // 开启步进
    quickSort(arr, 0, n-1, n);
    return 0;

}