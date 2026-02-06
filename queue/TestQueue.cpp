// TestQueue.cpp
#include <iostream>
#include "LinkedQueue.h"

using namespace std;

void testBasicOperations() {
    cout << "=== 测试基本操作 ===" << endl;
    LinkedQueue q;
    
    cout << "1. 初始队列是否为空: " << (q.isEmpty() ? "是" : "否") << endl;
    cout << "   初始大小: " << q.size() << endl;
    
    // 测试入队
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    
    cout << "2. 入队3个元素后大小: " << q.size() << endl;
    cout << "   队首元素: " << q.peek() << endl;
    
    // 测试出队
    q.dequeue();
    cout << "3. 出队1次后大小: " << q.size() << endl;
    cout << "   队首元素: " << q.peek() << endl;
    
    // 测试清空
    q.clear();
    cout << "4. 清空后是否为空: " << (q.isEmpty() ? "是" : "否") << endl;
    cout << "   清空后大小: " << q.size() << endl;
}

void testEdgeCases() {
    cout << "\n=== 测试边界情况 ===" << endl;
    LinkedQueue q;
    
    // 测试空队列出队
    q.dequeue();  // 应该不会崩溃
    
    // 测试空队列peek
    cout << "1. 空队列peek返回值: " << q.peek() << endl;
    
    // 测试单个元素入队出队
    q.enqueue(100);
    cout << "2. 单个元素入队后: 大小=" << q.size() 
              << ", 队首=" << q.peek() << endl;
    
    q.dequeue();
    cout << "3. 单个元素出队后: 大小=" << q.size() 
              << ", 是否为空=" << (q.isEmpty() ? "是" : "否") << endl;
    
    // 测试多个元素连续操作
    for (int i = 1; i <= 5; i++) {
        q.enqueue(i * 10);
    }
    cout << "4. 连续入队5个元素后: 大小=" << q.size() 
              << ", 队首=" << q.peek() << endl;
}

int main() {
    testBasicOperations();
    testEdgeCases();
    return 0;
}