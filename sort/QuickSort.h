#ifndef QUICKSORT_H
#define QUICKSORT_H

#include "config.h"

// 快速排序函数声明
void quickSort(int arr[], int low, int high);
int partition(int arr[], int low, int high);

// 迭代版本的快速排序
void quickSortIterative(int arr[], int l, int h);

#endif
