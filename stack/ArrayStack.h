#ifndef ARRAYSTACK_H  // 防止头文件被重复包含
#define ARRAYSTACK_H

class ArrayStack {
private:
    int* myArr;
    int capacity;
    int topIndex;
    
public:
    ArrayStack(int initCapacity = 10);
    ~ArrayStack();
    void push(int n);
    int pop();
    bool isEmpty();
    int size();

private:
    void resize();
};

#endif // ARRAYSTACK_H