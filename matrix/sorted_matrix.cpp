/**
 * @file sorted_matrix.cpp
 * @author Arunangshu Biswas (arunangshubsws@gmail.com)
 * @brief https://practice.geeksforgeeks.org/problems/sorted-matrix/0#
 * @version 0.1
 * @date 2020-11-19
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include <bits/stdc++.h>
using namespace std;

vector<int> sorted(vector<vector<int>> &matrix, int n)
{
    vector<int> result;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            result.push_back(matrix[i][j]);
        }
    }

    sort(result.begin(), result.end());

    return result;
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

        vector<int> result = sorted(matrix, n);
        for (int i = 0; i < n * n; i++)
        {
            cout << result[i] << " ";
        }
        cout << "\n";
    }

    return 0;
}