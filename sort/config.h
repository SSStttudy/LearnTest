#ifndef CONFIG_H
#define CONFIG_H

#include <iostream>
#include <stack>
#include <cstdlib>
#include <ctime>

using namespace std;

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void printArray(int arr[], int size)
{
    for (int i = 0 ;i < size; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

#endif