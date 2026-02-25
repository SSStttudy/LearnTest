
#ifndef BINARY_TREE_H
#define BINARY_TREE_H

#include <iostream>

struct TreeNode {
    int val;            // 节点存储的值
    TreeNode* left;     // 指向左子节点的指针
    TreeNode* right;    // 指向右子节点的指针
    
    // 构造函数
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// 函数声明
void preorderTraversal(TreeNode* node);
void inorderTraversal(TreeNode* node);
void postorderTraversal(TreeNode* node);

#endif