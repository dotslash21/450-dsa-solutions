/**
 * @file populate_inorder_successor.cpp
 * @author Arunangshu Biswas (arunangshubsws@gmail.com)
 * @brief https://practice.geeksforgeeks.org/problems/populate-inorder-successor-for-all-nodes/1#
 * @version 0.1
 * @date 2020-11-10
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

struct node
{
    int data;
    struct node *left;
    struct node *right;
    struct node *next;

    node(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
        next = NULL;
    }
};

struct node *Inorder(struct node *root)
{

    if (root->left == NULL)
        return root;
    Inorder(root->left);
}

void populateNext(struct node *root);

void insert(struct node *root, int n1, int n2, char lr)
{
    if (root == NULL)
        return;
    if (root->data == n1)
    {
        switch (lr)
        {
        case 'L':
            root->left = new node(n2);
            break;
        case 'R':
            root->right = new node(n2);
            break;
        }
    }
    else
    {
        insert(root->left, n1, n2, lr);
        insert(root->right, n1, n2, lr);
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {

        int n;
        cin >> n;
        struct node *root = NULL;
        while (n--)
        {
            char lr;
            int n1, n2;
            cin >> n1 >> n2;
            cin >> lr;
            if (root == NULL)
            {
                root = new node(n1);
                switch (lr)
                {
                case 'L':
                    root->left = new node(n2);
                    break;
                case 'R':
                    root->right = new node(n2);
                    break;
                }
            }
            else
            {
                insert(root, n1, n2, lr);
            }
        }
        populateNext(root);

        struct node *ptr = Inorder(root);
        while (ptr)
        {
            printf("%d->%d ", ptr->data, ptr->next ? ptr->next->data : -1);
            ptr = ptr->next;
        }
        cout << endl;
    }
    return 0;
}

/**
 * @brief Perform reverse inorder traversal to assign
 *        next pointer to previously visited node.
 * 
 * @param root The root of the BST.
 * @param prev The previously visited node.
 */
void traverse(struct node* root, struct node*& prev) {
    if (root == NULL) {
        return;
    }

    traverse(root->right, prev);
    
    root->next = prev;
    prev = root;

    traverse(root->left, prev);
}

/**
 * @brief Populate the next pointers of all the nodes
 *        of the tree to inorder successor.
 * 
 * @param p The root of the BST.
 */
void populateNext(struct node *p)
{
    struct node* prev = NULL;
    traverse(p, prev);
}