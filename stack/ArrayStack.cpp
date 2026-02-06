#include "ArrayStack.h"
#include <iostream>  // 为了使用cerr

ArrayStack::ArrayStack(int initCapacity) {
    capacity = initCapacity;
    myArr = new int[initCapacity];
    topIndex = -1;
}

ArrayStack::~ArrayStack() {
    delete[] myArr;
}

void ArrayStack::push(int value) {
    if (topIndex == capacity - 1) {
        resize();
    }
    myArr[++topIndex] = value;
}

int ArrayStack::pop() {
    if (isEmpty()) {
        std::cerr << "Error: Stack is empty!" << std::endl;
        return -1;
    }
    return myArr[topIndex--];
}

bool ArrayStack::isEmpty() {
    return topIndex == -1;  // 修正：应该是==，不是+1
}

int ArrayStack::size() {
    return topIndex + 1;
}

void ArrayStack::resize() {
    int newCapacity = capacity * 1.5;
    int* newArr = new int[newCapacity];
    for (int i = 0; i <= topIndex; i++) {
        newArr[i] = myArr[i];
    }
    delete[] myArr;
    capacity = newCapacity;
    myArr = newArr;
}