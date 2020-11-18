/**
 * @file find_a_specific_pair_in_matrix.cpp
 * @author Arunangshu Biswas (arunangshubsws@gmail.com)
 * @brief https://www.geeksforgeeks.org/find-a-specific-pair-in-matrix/
 * @version 0.1
 * @date 2020-11-19
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include <bits/stdc++.h>
using namespace std;

int findMaxPair(vector<vector<int>> &matrix, int n)
{
    int maxValue = INT_MIN;

    // preprocess last row
    int maxv = matrix[n - 1][n - 1];
    for (int i = n - 2; i > -1; i--)
    {
        maxv = max(maxv, matrix[n - 1][i]);
        matrix[n - 1][i] = maxv;
    }

    // preprocess last column
    maxv = matrix[n - 1][n - 1];
    for (int i = n - 2; i > -1; i--)
    {
        maxv = max(maxv, matrix[i][n - 1]);
        matrix[i][n - 1] = maxv;
    }

    for (int i = n - 2; i > -1; i--)
    {
        for (int j = n - 2; j > -1; j--)
        {
            // update maxValue
            maxValue = max(maxValue, matrix[i + 1][j + 1] - matrix[i][j]);
            // update matrix[i][j] to max form [i, j] to [n-1, n-1]
            matrix[i][j] = max(matrix[i][j], max(matrix[i][j + 1], matrix[i + 1][j]));
        }
    }

    return maxValue;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<vector<int>> matrix(n, vector<int>(n));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> matrix[i][j];
            }
        }
        cout << findMaxPair(matrix, n) << "\n";
    }

    return 0;
}