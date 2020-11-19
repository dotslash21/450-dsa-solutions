/**
 * @file common_elements_in_all_rows_of_a_matrix.cpp
 * @author Arunangshu Biswas (arunangshubsws@gmail.com)
 * @brief https://www.geeksforgeeks.org/common-elements-in-all-rows-of-a-given-matrix/
 * @version 0.1
 * @date 2020-11-19
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include <bits/stdc++.h>
using namespace std;

void printCommon(vector<vector<int>> &matrix, int r, int c)
{
    unordered_map<int, int> mp;

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (mp[matrix[i][j]] == i)
                mp[matrix[i][j]]++;
        }
    }

    for (auto it : mp)
    {
        if (it.second == r)
            cout << it.first << " ";
    }
    cout << "\n";
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int r, c;
        cin >> r >> c;
        vector<vector<int>> matrix(r, vector<int>(c));
        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                cin >> matrix[i][j];
            }
        }
        printCommon(matrix, r, c);
    }
}