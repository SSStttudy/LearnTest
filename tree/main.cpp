// main.cpp
#include "ExpressionTree.h"
#include<iostream>

#ifdef _WIN32
#include <windows.h>
#endif

int main() {
    // 设置控制台为UTF-8编码（Windows专用）
    #ifdef _WIN32
        SetConsoleOutputCP(65001);  // 设置输出编码为UTF-8
        SetConsoleCP(65001);        // 设置输入编码为UTF-8
    #endif

    // 构建表达式树
    ExpressionTreeNode* root = buildExampleTree1();
    
    // 遍历
    std::cout << "前序遍历: ";
    preorderTraversal(root);
    std::cout << std::endl;
    
    std::cout << "中序遍历: ";
    inorderTraversal(root);
    std::cout << std::endl;
    
    std::cout << "后序遍历: ";
    postorderTraversal(root);
    std::cout << std::endl;
    
    // 求值
    int result = evaluateExpressionTree(root);
    std::cout << "表达式树求值结果: " << result << std::endl;
    
    // 清理内存
    delete root;
    
    return 0;
}