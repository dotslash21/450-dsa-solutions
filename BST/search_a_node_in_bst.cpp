/**
 * @file search_a_node_in_bst.cpp
 * @author Arunangshu Biswas (arunangshubsws@gmail.com)
 * @brief https://www.geeksforgeeks.org/binary-search-tree-set-1-search-and-insertion/
 * @version 0.1
 * @date 2020-11-08
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node *left, *right;
    Node(int data)
    {
        this->data = data;
        left = right = NULL;
    }
};

/**
 * @brief Check if a node exists in BST.
 * 
 * @param root The root node of BST.
 * @param key The key if the node to be searched.
 * @return true If node exists.
 * @return false If node doesn't exists.
 */
bool hasNode(Node* root, int key) {
    while (root != NULL) {
        if (root->data == key) {
            return true;
        } else if (root->data > key) {
            root = root->left;
        } else {
            root = root->right;
        }
    }

    return false;
}

int main()
{
    struct Node* root = new Node(7);
    root->left = new Node(3);
    root->left->left = new Node(2);
    root->left->left->left = new Node(1);
    root->left->right = new Node(5);
    root->left->right->left = new Node(4);
    root->left->right->right = new Node(6);
    root->right = new Node(9);
    root->right->left = new Node(8);
    root->right->right = new Node(10);
 
    int key = 6;
 
    if (hasNode(root, key))
        cout << "YES";
    else
        cout << "NO";
 
    return 0;
}