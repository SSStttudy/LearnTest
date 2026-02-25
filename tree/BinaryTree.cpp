#include<iostream>
#include "BinaryTree.h"

using namespace std;

struct TreeNode {
    int val;           // 节点存储的值
    TreeNode* left;    // 指向左子节点的指针
    TreeNode* right;   // 指向右子节点的指针
    // 构造函数
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

void preorderTraversal(TreeNode* node) {
    if (node == nullptr) {  // 基线条件：遇到空节点就返回
        return;
    }
    // 1. 访问当前节点（比如打印）
    cout << node->val << " ";
    // 2. 递归遍历左子树
    preorderTraversal(node->left);
    // 3. 递归遍历右子树
    preorderTraversal(node->right);
}

void inorderTraversal(TreeNode *node){
    if (node == nullptr) {  // 基线条件：遇到空节点就返回
        return;
    }
    inorderTraversal(node->left);

    cout << node->val << " ";
    
    inorderTraversal(node->right);
}

void postorderTraversal(TreeNode *node){
    if (node == nullptr) {  // 基线条件：遇到空节点就返回
        return;
    }
    postorderTraversal(node->left);
    
    postorderTraversal(node->right);

    cout << node->val << " ";
}

