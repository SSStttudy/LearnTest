#ifndef LINKEDSTACK_H
#define LINKEDSTACK_H

// 链表节点结构
struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

class LinkedStack {
private:
    Node* topNode;  // 栈顶指针
    int count;      // 元素个数
    
public:
    LinkedStack();
    ~LinkedStack();
    void push(int value);
    int pop();
    int top() const;
    bool isEmpty() const;
    int size() const;
};

#endif // LINKEDSTACK_H