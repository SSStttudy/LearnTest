#include "ExpressionTree.h"
#include <iostream>

using namespace std;

ExpressionTreeNode::ExpressionTreeNode(int val): type(OPERAND), value(val), op('\0'), left(nullptr), right(nullptr) {}

ExpressionTreeNode::ExpressionTreeNode(char oper): type(OPERATOR), value(0), op(oper), left(nullptr), right(nullptr){
}

ExpressionTreeNode::~ExpressionTreeNode(){
}

void preorderTraversal(ExpressionTreeNode *root){
    if (root == nullptr) return;
    if (root->type == OPERAND) {
        cout << root->value << " ";
    } else {
        cout << root->op << " ";
    }
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

void inorderTraversal(ExpressionTreeNode *root)
{
    if (root == nullptr) return;
    if (root->left != nullptr) {
        inorderTraversal(root->left);
    }
    if (root->type == OPERAND) {
        cout << root->value << " ";
    } else {
        cout << root->op << " ";
    }
    if (root->right != nullptr) {
        inorderTraversal(root->right);
    }
}

void postorderTraversal(ExpressionTreeNode *root)
{
    if (root == nullptr) return;
    postorderTraversal(root->left);
    postorderTraversal(root->right);
    if (root->type == OPERAND) {
        cout << root->value << " ";
    } else {
        cout << root->op << " ";
    }
}

int evaluateExpressionTree(ExpressionTreeNode *root)
{
    if (root == nullptr) return -1;
   
    if (root->type == OPERATOR) {
        int a = evaluateExpressionTree(root->left);
        int b = evaluateExpressionTree(root->right);
        char c = root->op;
        switch (c)
        {
        case '+': return a+b;
        case '-': return a-b;
        case '*': return a*b;
        case '/':
            if(b != 0){
                return a/b;
            } else {
                cout << "错误：除数不能为零！" << endl;
            }
        default:
            cout << "错误：未知的运算符！" << endl;
            return -1;
        }
    } else if (root->type == OPERAND){
        return root->value;
    }

    return -1;
}

ExpressionTreeNode *buildExampleTree1()
{
    // 创建节点
    ExpressionTreeNode* plusNode = new ExpressionTreeNode('+');
    ExpressionTreeNode* multiplyNode = new ExpressionTreeNode('*');
    ExpressionTreeNode* num3 = new ExpressionTreeNode(3);
    ExpressionTreeNode* num4 = new ExpressionTreeNode(4);
    ExpressionTreeNode* num5 = new ExpressionTreeNode(5);
    
    // 构建连接
    plusNode->left = num3;
    plusNode->right = multiplyNode;
    multiplyNode->left = num4;
    multiplyNode->right = num5;
    
    return plusNode; // 返回根节点

}
