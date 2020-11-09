/**
 * @file delete_node_in_bst.cpp
 * @author Arunangshu Biswas (arunangshubsws@gmail.com)
 * @brief https://leetcode.com/problems/delete-node-in-a-bst
 * @version 0.1
 * @date 2020-11-09
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public: 
    bool isLeaf(TreeNode* node) {
        return node->left == NULL && node->right == NULL;
    }

    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == NULL) {
            return root;
        }

        if (root->val < key) {
            // Key lies on the right subtree.
            root->right = deleteNode(root->right, key);
            return root;
        } else if (root->val > key) {
            // Key lies on the left subtree.
            root->left = deleteNode(root->left, key);
            return root;
        } else {
            // key found!
            if (isLeaf(root)) {
                // Found key node is a leaf node
                delete root;
                return NULL;
            } else if (root->left == NULL) {
                // Found key node has only right subtree
                TreeNode* temp = root->right;
                root->right = NULL;
                delete root;
                return temp;
            } else if (root->right == NULL) {
                // Found key node has only left subtree
                TreeNode* temp = root->left;
                root->left = NULL;
                delete root;
                return temp;
            } else {
                // Found key node has both child subtrees
                // Find the inorder successor and replace
                // it with the node to be deleted
                TreeNode* rightMin = root->right;
                while (rightMin->left != NULL)
                {
                    rightMin = rightMin->left;
                }
                root->val = rightMin->val;
                root->right = deleteNode(root->right, rightMin->val);
                return root;
            }
        }
    }
};