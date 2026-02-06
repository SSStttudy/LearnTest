#include "LinkedStack.h"
#include <iostream>
#include <stdexcept>

LinkedStack::LinkedStack() : topNode(nullptr), count(0) {}

LinkedStack::~LinkedStack() {
    // 释放所有节点内存
    while (!isEmpty()) {
        pop();
    }
}

void LinkedStack::push(int value) {
    Node* newNode = new Node(value);
    newNode->next = topNode;  // 新节点指向当前栈顶
    topNode = newNode;        // 更新栈顶指针
    count++;
}

int LinkedStack::pop() {
    if (isEmpty()) {
        throw std::runtime_error("Stack is empty!");
    }
    
    Node* nodeToDelete = topNode;
    int value = nodeToDelete->data;
    topNode = topNode->next;  // 栈顶指针下移
    delete nodeToDelete;      // 释放原栈顶节点
    count--;
    
    return value;
}

int LinkedStack::top() const {
    if (isEmpty()) {
        throw std::runtime_error("Stack is empty!");
    }
    return topNode->data;
}

bool LinkedStack::isEmpty() const {
    return topNode == nullptr;
}

int LinkedStack::size() const {
    return count;
}