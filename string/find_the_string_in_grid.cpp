/**
 * @file find_the_string_in_grid.cpp
 * @author Arunangshu Biswas (arunangshubsws@gmail.com)
 * @brief https://practice.geeksforgeeks.org/problems/find-the-string-in-grid/0#
 * @version 0.1
 * @date 2020-12-01
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include <bits/stdc++.h>
using namespace std;

bool findUp(int i, int j, vector<vector<char>> &matrix, string str)
{
    int n = matrix.size(), m = matrix[0].size();

    if (i + 1 < str.size())
        return false;

    for (int k = 0; k < str.size(); k++)
    {
        if (matrix[i - k][j] != str[k])
            return false;
    }

    return true;
}

bool findDown(int i, int j, vector<vector<char>> &matrix, string str)
{
    int n = matrix.size(), m = matrix[0].size();

    if (n - i < str.size())
        return false;

    for (int k = 0; k < str.size(); k++)
    {
        if (matrix[i + k][j] != str[k])
            return false;
    }

    return true;
}

bool findLeft(int i, int j, vector<vector<char>> &matrix, string str)
{
    int n = matrix.size(), m = matrix[0].size();

    if (j + 1 < str.size())
        return false;

    for (int k = 0; k < str.size(); k++)
    {
        if (matrix[i][j - k] != str[k])
            return false;
    }

    return true;
}

bool findRight(int i, int j, vector<vector<char>> &matrix, string str)
{
    int n = matrix.size(), m = matrix[0].size();

    if (m - j < str.size())
        return false;

    for (int k = 0; k < str.size(); k++)
    {
        if (matrix[i][j + k] != str[k])
            return false;
    }

    return true;
}

bool findDiagonalNE(int i, int j, vector<vector<char>> &matrix, string str)
{
    int n = matrix.size(), m = matrix[0].size();

    if (i + 1 < str.size() || m - j < str.size())
        return false;

    for (int k = 0; k < str.size(); k++)
    {
        if (matrix[i - k][j + k] != str[k])
            return false;
    }

    return true;
}

bool findDiagonalSE(int i, int j, vector<vector<char>> &matrix, string str)
{
    int n = matrix.size(), m = matrix[0].size();

    if (n - i < str.size() || m - j < str.size())
        return false;

    for (int k = 0; k < str.size(); k++)
    {
        if (matrix[i + k][j + k] != str[k])
            return false;
    }

    return true;
}

bool findDiagonalNW(int i, int j, vector<vector<char>> &matrix, string str)
{
    int n = matrix.size(), m = matrix[0].size();

    if (i + 1 < str.size() || j + 1 < str.size())
        return false;

    for (int k = 0; k < str.size(); k++)
    {
        if (matrix[i - k][j - k] != str[k])
            return false;
    }

    return true;
}

bool findDiagonalSW(int i, int j, vector<vector<char>> &matrix, string str)
{
    int n = matrix.size(), m = matrix[0].size();

    if (n - i < str.size() || j + 1 < str.size())
        return false;

    for (int k = 0; k < str.size(); k++)
    {
        if (matrix[i + k][j - k] != str[k])
            return false;
    }

    return true;
}

void find(vector<vector<char>> &matrix, string str)
{
    int n = matrix.size(), m = matrix[0].size();

    int count = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (
                findUp(i, j, matrix, str) ||
                findDown(i, j, matrix, str) ||
                findLeft(i, j, matrix, str) ||
                findRight(i, j, matrix, str) ||
                findDiagonalNE(i, j, matrix, str) ||
                findDiagonalSE(i, j, matrix, str) ||
                findDiagonalNW(i, j, matrix, str) ||
                findDiagonalSW(i, j, matrix, str))
            {
                count++;
                cout << i << " " << j << ", ";
            }
        }
    }

    if (count == 0)
        cout << "-1";

    cout << "\n";
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> matrix(n, vector<char>(m));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> matrix[i][j];
            }
        }
        string str;
        cin >> str;

        find(matrix, str);
    }

    return 0;
}