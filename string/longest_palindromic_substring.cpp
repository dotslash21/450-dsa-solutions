/**
 * @file longest_palindromic_substring.cpp
 * @author Arunangshu Biswas (arunangshubsws@gmail.com)
 * @brief https://practice.geeksforgeeks.org/problems/longest-palindrome-in-a-string/0
 * @version 0.1
 * @date 2020-11-22
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include <bits/stdc++.h>
using namespace std;

string longestPalindromicSubstring(string &s)
{
    int n = s.size();
    if (n == 1)
        return s;

    string result = "";
    vector<vector<int>> dp(n, vector<int>(n, 0));

    for (int i = n - 1; i > -1; i--)
    {
        dp[i][i] = 1;
        result = s.substr(i, 1);
    }

    for (int i = n - 2; i > -1; i--)
    {
        if (s[i] == s[i + 1])
        {
            dp[i][i + 1] = 1;
            result = s.substr(i, 2);
        }
    }

    for (int k = 2; k < n; k++)
    {
        for (int i = n - k - 1; i > -1; i--)
        {
            int j = i + k;

            if (s[i] == s[j] && dp[i + 1][j - 1] == 1)
            {
                dp[i][j] = 1;
                result = s.substr(i, k + 1);
            }
        }
    }

    return result;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;

        cout << longestPalindromicSubstring(s) << "\n";
    }

    return 0;
}