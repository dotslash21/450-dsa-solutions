/**
 * @file count_palindromic_subsequences.cpp
 * @author Arunangshu Biswas (arunangshubsws@gmail.com)
 * @brief https://practice.geeksforgeeks.org/problems/count-palindromic-subsequences/1#
 * @version 0.1
 * @date 2020-11-30
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include <iostream>
#include <cstring>
using namespace std;

// Function return the total palindromic subsequence
int countPS(string str);

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string str;
        cin >> str;
        cout << countPS(str) << endl;
    }
}

/*You are required to complete below method */
int countPS(string str)
{
    int n = str.size();
    int table[n][n];

    // Traverse diagonally base to top right direction
    int i = 0, j = 0;
    while (j < n)
    {
        i = 0;

        while (i < n && i + j < n)
        {
            // Trivial case single character
            if (j == 0)
            {
                table[i][i + j] = 1;
            }
            // Trivial case double character
            else if (j == 1)
            {
                if (str[i] == str[i + j])
                    table[i][i + j] = 3;
                else
                    table[i][i + j] = 2;
            }
            else
            {
                if (str[i] == str[i + j])
                    table[i][i + j] = table[i][i + j - 1] + table[i + 1][i + j] + 1;
                else
                    table[i][i + j] = table[i][i + j - 1] + table[i + 1][i + j] - table[i + 1][i + j - 1];
            }

            i++;
        }

        j++;
    }

    return table[0][n - 1];
}