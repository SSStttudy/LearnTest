// LinkedQueue.h
#ifndef MYQUEUE_H
#define MYQUEUE_H

class LinkedQueue {
private:
    struct Node {
        int data;
        Node* next;
        Node(int val) : data(val), next(nullptr) {}
    };
    
    Node* front;  // 指向队列头部（出队的位置）
    Node* rear;   // 指向队列尾部（入队的位置）
    int count;    // 队列中元素的数量

public:
    LinkedQueue();           // 构造函数
    ~LinkedQueue();          // 析构函数
    
    // 基本操作
    void enqueue(int value);  // 入队
    void dequeue();           // 出队
    int peek() const;         // 查看队首元素
    int size() const;         // 返回队列大小
    bool isEmpty() const;     // 判断队列是否为空
    
    // 可选：清空队列
    void clear();
    
    // 禁用拷贝构造函数和赋值运算符（防止浅拷贝问题）
    LinkedQueue(const LinkedQueue&) = delete;
    LinkedQueue& operator=(const LinkedQueue&) = delete;
};

#endif