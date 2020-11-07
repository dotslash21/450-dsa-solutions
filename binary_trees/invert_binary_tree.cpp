/**
 * @file invert_binary_tree.cpp
 * @author Arunangshu Biswas (arunangshubsws@gmail.com)
 * @brief https://leetcode.com/problems/invert-binary-tree/submissions/,
 *        https://www.geeksforgeeks.org/create-a-mirror-tree-from-the-given-binary-tree/
 * @version 0.1
 * @date 2020-11-07
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
    /**
     * @brief Invert the given binary tree.
     * 
     * @param root The root node of the given binary tree.
     * @return TreeNode* The root node of the inverted binary tree,
     */
    TreeNode* invertTree(TreeNode* root) {
        if (root == NULL) {
            return root;
        }

        // Invert the childern first
        invertTree(root->left);
        invertTree(root->right);

        // Then, invert the parent
        TreeNode* temp = root->left;
        root->left = root->right;
        root->right = temp;

        return root;
    }
};