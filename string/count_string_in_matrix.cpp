/**
 * @file count_string_in_matrix.cpp
 * @author Arunangshu Biswas (arunangshubsws@gmail.com)
 * @brief https://www.geeksforgeeks.org/find-count-number-given-string-present-2d-character-array/
 * @version 0.1
 * @date 2020-11-30
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include <bits/stdc++.h>
using namespace std;

bool dfs(int i, int j, vector<vector<char>> &matrix, int idx, string str)
{
    if (idx == str.size())
        return true;

    if (i < 0 || i >= matrix.size())
        return false;

    if (j < 0 || j >= matrix[0].size())
        return false;

    if (matrix[i][j] != str[idx])
        return false;

    return dfs(i + 1, j, matrix, idx + 1, str) ||
           dfs(i - 1, j, matrix, idx + 1, str) ||
           dfs(i, j + 1, matrix, idx + 1, str) ||
           dfs(i, j - 1, matrix, idx + 1, str);
}

int count(vector<vector<char>> &matrix, string str)
{
    int m = matrix.size(), n = matrix[0].size();

    int count = 0;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            count += dfs(i, j, matrix, 0, str) ? 1 : 0;
        }
    }

    return count;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int m, n;
        cin >> m >> n;
        vector<vector<char>> matrix(m, vector<char>(n));
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> matrix[i][j];
            }
        }
        string str;
        cin >> str;

        // vector<vector<char>> matrix = {
        //     {'D', 'D', 'D', 'G', 'D', 'D'},
        //     {'B', 'B', 'D', 'E', 'B', 'S'},
        //     {'B', 'S', 'K', 'E', 'B', 'K'},
        //     {'D', 'D', 'D', 'D', 'D', 'E'},
        //     {'D', 'D', 'D', 'D', 'D', 'E'},
        //     {'D', 'D', 'D', 'D', 'D', 'G'}};
        // string str = "GEEKS";

        // vector<vector<char>> matrix = {
        //     {'B', 'B', 'M', 'B', 'B', 'B'},
        //     {'C', 'B', 'A', 'B', 'B', 'B'},
        //     {'I', 'B', 'G', 'B', 'B', 'B'},
        //     {'G', 'B', 'I', 'B', 'B', 'B'},
        //     {'A', 'B', 'C', 'B', 'B', 'B'},
        //     {'M', 'C', 'I', 'G', 'A', 'M'}};
        // string str = "MAGIC";

        cout << count(matrix, str) << "\n";
    }

    return 0;
}