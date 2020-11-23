/**
 * @file edit_distance.cpp
 * @author Arunangshu Biswas (arunangshubsws@gmail.com)
 * @brief https://practice.geeksforgeeks.org/problems/edit-distance3702/1
 * @version 0.1
 * @date 2020-11-23
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int editDistance(string s, string t)
    {
        int m = s.size();
        int n = t.size();

        int dp[m + 1][n + 1];

        for (int i = 0; i <= m; i++)
        {
            for (int j = 0; j <= n; j++)
            {
                if (i == 0)
                    dp[i][j] = j;
                else if (j == 0)
                    dp[i][j] = i;
                else if (s[i - 1] == t[j - 1])
                    dp[i][j] = dp[i - 1][j - 1];
                else
                    dp[i][j] = 1 + min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1]));
            }
        }

        return dp[m][n];
    }

    int editDistanceRecursive(string s, string t, int m, int n)
    {
        if (m == -1)
        {
            return n + 1;
        }
        else if (n == -1)
        {
            return m + 1;
        }

        if (s[m] == t[n])
        {
            return editDistanceRecursive(s, t, m - 1, n - 1);
        }
        else
        {
            return 1 + min(editDistanceRecursive(s, t, m - 1, n - 1),
                           min(editDistanceRecursive(s, t, m - 1, n),
                               editDistanceRecursive(s, t, m, n - 1)));
        }
    }
};

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        string s, t;
        cin >> s >> t;
        Solution ob;
        int ans = ob.editDistance(s, t);
        // int ans = ob.editDistanceRecursive(s, t, s.size() - 1, t.size() - 1);
        cout << ans << "\n";
    }
    return 0;
}