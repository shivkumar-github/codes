/*
Coding Ninjas
https://www.codingninjas.com/studio/problems/count-leaf-nodes_893055
Problem statement
You are given a Binary tree. You have to count and return the number of leaf nodes present in it.

A binary tree is a tree data structure in which each node has at most two children, which are referred to as the left child and the right child

A node is a leaf node if both left and right child nodes of it are NULL.
*/

#include <iostream>
using namespace std;

void inorder(BinaryTreeNode<int> *root, int &count)
{
    // base case
    if (root == NULL) return;
    inorder(root->left, count);
    // leaf node
    if (root->left == NULL && root->right == NULL) count++; // -> print ki jagah count ko increase kardo
    inorder(root->right, count);
} // you can do the problem with any of the pre,in or post traversal

int noOfLeafNodes(BinaryTreeNode<int> *root)
{
    int cnt = 0;
    inorder(root, count);
    return count;
}