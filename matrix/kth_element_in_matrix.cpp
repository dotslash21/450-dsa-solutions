/**
 * @file kth_element_in_matrix.cpp
 * @author Arunangshu Biswas (arunangshubsws@gmail.com)
 * @brief https://practice.geeksforgeeks.org/problems/kth-element-in-matrix/1
 * @version 0.1
 * @date 2020-11-19
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include <bits/stdc++.h>
#define MAX 1000
using namespace std;

int mat[MAX][MAX];
int kthSmallest(int mat[MAX][MAX], int n, int k);

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                cin >> mat[i][j];
        int r;
        cin >> r;
        cout << kthSmallest(mat, n, r) << endl;
    }

    return 0;
}

struct HeapNode
{
    int value;
    int row;
    int column;

    HeapNode()
    {
        value = 0;
        row = -1;
        column = -1;
    }

    HeapNode(int _value, int _row, int _column)
    {
        value = _value;
        row = _row;
        column = _column;
    }
};

struct CompareHeapNode
{
    bool operator()(const HeapNode &a, const HeapNode &b)
    {
        return a.value > b.value;
    }
};

int kthSmallest(int mat[MAX][MAX], int n, int k)
{
    if (k <= 0 || k > n * n)
        throw invalid_argument("The value of k must be in between 1 and n * n");

    priority_queue<HeapNode, vector<HeapNode>, CompareHeapNode> minHeap;
    for (int i = 0; i < n; i++)
        minHeap.push(HeapNode(mat[0][i], 0, i));

    HeapNode root;
    for (int i = 0; i < k; i++)
    {
        root = minHeap.top();
        minHeap.pop();

        int nextVal = (root.row < (n - 1)) ? mat[root.row + 1][root.column] : INT_MAX;

        minHeap.push(HeapNode(nextVal, root.row + 1, root.column));
    }

    return root.value;
}