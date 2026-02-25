// ExpressionTree.h
#ifndef EXPRESSION_TREE_H
#define EXPRESSION_TREE_H

#include <iostream>
#include <stack>
#include <string>

// 节点类型枚举
enum NodeType {
    OPERAND,    // 操作数
    OPERATOR    // 运算符
};

// 表达式树节点结构
struct ExpressionTreeNode {
    NodeType type;      // 节点类型
    int value;          // 存储操作数值（当type == OPERAND时有效）
    char op;            // 存储运算符（当type == OPERATOR时有效）
    ExpressionTreeNode* left;
    ExpressionTreeNode* right;
    
    // 操作数构造函数
    ExpressionTreeNode(int val);
    
    // 运算符构造函数  
    ExpressionTreeNode(char oper);
    
    // 析构函数（可选，用于释放内存）
    ~ExpressionTreeNode();
};

// 遍历函数声明
void preorderTraversal(ExpressionTreeNode* root);
void inorderTraversal(ExpressionTreeNode* root);
void postorderTraversal(ExpressionTreeNode* root);

// 表达式求值函数声明
int evaluateExpressionTree(ExpressionTreeNode* root);

// 构建表达式树的辅助函数声明（手动构建示例）
ExpressionTreeNode* buildExampleTree1();  // 构建 3 + 4 * 5 的表达式树

#endif