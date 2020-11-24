/**
 * @file word_break.cpp
 * @author Arunangshu Biswas (arunangshubsws@gmail.com)
 * @brief https://practice.geeksforgeeks.org/problems/word-break1352/1#
 * @version 0.1
 * @date 2020-11-24
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include <bits/stdc++.h>
using namespace std;

int wordBreak(string A, vector<string> &B);

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<string> dict;
        for (int i = 0; i < n; i++)
        {
            string S;
            cin >> S;
            dict.push_back(S);
        }
        string line;
        cin >> line;
        cout << wordBreak(line, dict) << "\n";
    }
}

bool hasString(string str, vector<string> &dict)
{
    for (string word : dict)
    {
        if (word.compare(str) == 0)
            return true;
    }

    return false;
}

// A : given string to search
// B : vector of available strings
int wordBreak(string A, vector<string> &B)
{
    int n = A.size();
    if (n == 0)
        return true;

    bool dp[n + 1];
    memset(dp, false, sizeof(dp));

    for (int i = 1; i <= n; i++)
    {
        if (dp[i] == false && hasString(A.substr(0, i), B))
            dp[i] = true;

        if (dp[i] == true)
        {
            if (i == n)
                return true;

            for (int j = i + 1; j <= n; j++)
            {
                if (dp[j] == false && hasString(A.substr(i, j - i), B))
                    dp[j] = true;

                if (j == n && dp[j] == true)
                    return true;
            }
        }
    }

    return false;
}