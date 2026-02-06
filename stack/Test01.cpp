#include <iostream>
#include "ArrayStack.h"

using namespace std;

int main() {
    ArrayStack stack(3);  // 初始容量3，会触发扩容
    
    cout << "Is empty? " << stack.isEmpty() << endl;  // 应为1(true)
    
    stack.push(10);
    stack.push(20);
    stack.push(30);
    cout << "Size after 3 pushes: " << stack.size() << endl;  // 应为3
    
    stack.push(40);  // 触发扩容
    cout << "Size after 4th push: " << stack.size() << endl;  // 应为4
    
    cout << "Pop: " << stack.pop() << endl;  // 应为40
    cout << "Top after pop: " << stack.pop() << endl;  // 应为30
    cout << "Size after 2 pops: " << stack.size() << endl;  // 应为2
    
    return 0;
}