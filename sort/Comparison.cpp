#include <iostream>
#include <cstdlib>
#include <ctime>
#include "QuickSort.h"
#include "MergeSort.h"

using namespace std;

// 生成随机数组
void generateRandomArray(int arr[], int n, int maxValue = 10000) {
    for (int i = 0; i < n; ++i)
        arr[i] = rand() % maxValue;
}

// 复制数组
void copyArray(int src[], int dst[], int n) {
    for (int i = 0; i < n; ++i)
        dst[i] = src[i];
}

// 检查数组是否升序排序
bool isSorted(int arr[], int n) {
    for (int i = 1; i < n; ++i)
        if (arr[i] < arr[i-1])
            return false;
    return true;
}

// 单个测试用例
void testSort(int arr[], int n, const string& name, void (*sortFunc)(int[], int, int)) {
    int* temp = new int[n];
    copyArray(arr, temp, n);
    
    sortFunc(temp, 0, n - 1);
    
    cout << name << ": ";
    if (isSorted(temp, n))
        cout << "✓ 排序正确";
    else
        cout << "✗ 排序错误";
    
    // 显示前5个元素和后5个元素（仅当n<=20时显示全部）
    cout << "  数组: [";
    if (n <= 20) {
        for (int i = 0; i < n; ++i)
            cout << temp[i] << (i == n-1 ? "" : " ");
    } else {
        for (int i = 0; i < 5; ++i) cout << temp[i] << " ";
        cout << "... ";
        for (int i = n-5; i < n; ++i) cout << temp[i] << (i == n-1 ? "" : " ");
    }
    cout << "]" << endl;
    
    delete[] temp;
}

int main() {
    srand(time(0));
    
    cout << "=========================================" << endl;
    cout << "    快速排序 & 归并排序 简单对数测试" << endl;
    cout << "=========================================" << endl;
    
    // 测试不同规模的数组（对数增长）
    int testSizes[] = {10, 50, 100, 500, 1000, 5000, 10000};
    int numTests = sizeof(testSizes) / sizeof(testSizes[0]);
    
    for (int i = 0; i < numTests; ++i) {
        int n = testSizes[i];
        cout << "\n----- 数组大小: " << n << " -----" << endl;
        
        int* original = new int[n];
        generateRandomArray(original, n);
        
        testSort(original, n, "快速排序(递归)", quickSort);
        testSort(original, n, "归并排序(递归)", mergeSort);
        
        delete[] original;
    }
    
    // 特殊边界测试
    cout << "\n----- 边界情况测试 -----" << endl;
    
    // 已排序数组
    int sorted[] = {1,2,3,4,5,6,7,8,9,10};
    testSort(sorted, 10, "快速排序(已排序)", quickSort);
    testSort(sorted, 10, "归并排序(已排序)", mergeSort);
    
    // 逆序数组
    int reversed[] = {10,9,8,7,6,5,4,3,2,1};
    testSort(reversed, 10, "快速排序(逆序)", quickSort);
    testSort(reversed, 10, "归并排序(逆序)", mergeSort);
    
    // 全部相等的数组
    int allEqual[] = {7,7,7,7,7,7,7,7,7,7};
    testSort(allEqual, 10, "快速排序(全等)", quickSort);
    testSort(allEqual, 10, "归并排序(全等)", mergeSort);
    
    // 单个元素
    int single[] = {42};
    testSort(single, 1, "快速排序(单元素)", quickSort);
    testSort(single, 1, "归并排序(单元素)", mergeSort);
    
    // 空数组（n=0，需要特殊处理）
    cout << "\n空数组测试: 跳过（函数需传入 n>0）" << endl;
    
    cout << "\n=========================================" << endl;
    cout << "                测试完成" << endl;
    cout << "=========================================" << endl;
    
    return 0;
}