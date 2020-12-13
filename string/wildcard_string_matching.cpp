/**
 * @file wildcard_string_matching.cpp
 * @author Arunangshu Biswas (arunangshubsws@gmail.com)
 * @brief https://www.geeksforgeeks.org/wildcard-pattern-matching/
 * @version 0.1
 * @date 2020-12-13
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include <bits/stdc++.h>
using namespace std;

bool match(string s1, string s2)
{
    if (s1.size() == 0)
        return s2.size() == 0;

    // empty pattern can match with empty string
    vector<vector<bool>> dp(s1.size() + 1, vector<bool>(s2.size() + 1, false));

    dp[0][0] = true;

    // Only '*' can match with empty string
    for (int i = 1; i <= s1.size(); i++)
    {
        if (s1[i - 1] == '*')
            dp[i][0] = dp[i - 1][0];
    }

    for (int i = 1; i <= s1.size(); i++)
    {
        for (int j = 1; j <= s2.size(); j++)
        {
            if (s1[i - 1] == '?' || s1[i - 1] == s2[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1];
            }
            else if (s1[i - 1] == '*')
            {
                dp[i][j] = (dp[i - 1][j] || dp[i][j - 1]);
            }
            else
            {
                dp[i][j] = false;
            }
        }
    }

    return dp[s1.size()][s2.size()];
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s1, s2;
        cin >> s1 >> s2;
        cout << (match(s1, s2) ? "Yes\n" : "No\n");
    }

    return 0;
}