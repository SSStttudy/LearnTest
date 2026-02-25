//排序算法可视化（基于控制台）
//note:1.“遍历取极值”是关键：找到数组的最大值maxVal和最小值minVal，然后用线性映射将每个元素val映射到1 + (val - minVal) * (maxHeight - 1) / (maxVal - minVal)，其中maxHeight是你设定的最大柱子长度（例如20）。这样可以保证最小值对应1个字符，最大值对应maxHeight个字符。
//      height = 1 + (val - minVal) * (maxHeight - 1) / (maxVal - minVal)

#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
#include <thread>
using namespace std;

bool stepMode = false; // 全局或外部变量控制

void printArray (int arr[], int n, int highlight1 = -1, int highlight2 = -1, int delayMs = 200) {
    //清屏
    system("cls");

    //求极值
    int minVal = arr[0],maxVal = arr[0];
    for(int i = 1; i < n; ++i){
        if(arr[i] > maxVal)maxVal = arr[i];
        if(arr[i] < minVal)minVal = arr[i];
    }

    const int MAX_HEIGHT = 20; //最大高度
    vector<int> heights(n);

    if (minVal == maxVal){  //避免除零错误
        fill(heights.begin(),heights.end(),MAX_HEIGHT/2);
    } else {
        for (int i = 0; i < n; ++i){
            heights[i] = 1 + (arr[i] - minVal)*(MAX_HEIGHT - 1) / (maxVal - minVal);
        }
    } 

    // 横向打印
    for(int row = MAX_HEIGHT; row >= 1; --row) {
        for (int i = 0; i < n; ++i) {
            if(heights[i] >= row) {
                if(i == highlight1 || i == highlight2)
                    cout << " * ";
                else 
                    cout << " # ";
            } else {
                cout << "   ";
            }
        }
        cout << endl;
    }

    // 打印数值
    for(int i = 0; i < n; ++i){
        printf("%3d",arr[i]);
    }
    cout << endl;

    if (stepMode) {
        cout << "按回车键继续...";
        cin.get(); // 等待回车
    } else {
        this_thread::sleep_for(chrono::milliseconds(delayMs));
    }
}

