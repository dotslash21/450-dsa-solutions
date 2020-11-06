/**
 * @file huffman_encoding.cpp
 * @author Arunangshu Biswas (arunangshubsws@gmail.com)
 * @brief https://www.geeksforgeeks.org/huffman-coding-greedy-algo-3/
 * @version 0.1
 * @date 2020-11-06
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include <bits/stdc++.h>
using namespace std;

struct Node {
    char alphabet;
    int frequency;
    Node* left;
    Node* right;

    Node() {
        alphabet = '\0';
        frequency = -1;
        left = NULL;
        right = NULL;
    }
};

struct compare
{
    bool operator()(Node* a, Node* b) {
        return a->frequency > b->frequency;
    }
};

void print(Node* root, string code) {
    if (root->alphabet != '\0') {
        cout << code << " ";
        return;
    }

    print(root->left, code + "0");
    print(root->right, code + "1");
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int n = s.size();
        priority_queue<Node*, vector<Node*>, compare> pq;
        for (int i = 0; i < n; i++) {
            Node *node = new Node();
            node->alphabet = s[i];
            cin >> node->frequency;
            pq.push(node);
        }

        while (pq.size() >= 2)
        {
            Node* a = pq.top();
            pq.pop();
            Node* b = pq.top();
            pq.pop();

            Node* c = new Node();
            c->frequency = a->frequency + b->frequency;
            c->left = a;
            c->right = b;

            pq.push(c);
        }
        
        Node* root = pq.top();
        print(root, "");
        cout << "\n";
    }
}