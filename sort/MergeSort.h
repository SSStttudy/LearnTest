#ifndef MERGESORT_H
#define MERGESORT_H

//#include "config.h";

// 归并排序函数声明
void mergeSort(int arr[], int l, int r);
void mergeSortIterative(int arr[], int n);

// 内部使用的合并函数（可选，可以只在cpp文件中声明）
void merge(int arr[], int l, int m, int r);

#endif