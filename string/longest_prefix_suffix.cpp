/**
 * @file longest_prefix_suffix.cpp
 * @author Arunangshu Biswas (arunangshubsws@gmail.com)
 * @brief https://practice.geeksforgeeks.org/problems/longest-prefix-suffix2527/1
 * @version 0.1
 * @date 2020-11-28
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include <bits/stdc++.h>
using namespace std;

//User function template for C++
class Solution
{
public:
    int lps(string s)
    {
        if (s.size() <= 1)
            return 0;

        vector<int> lps(s.size());
        lps[0] = 0;

        int i = 0, j = 1;
        while (j < s.size())
        {
            if (s[j] == s[i])
            {
                lps[j] = i + 1;
                i++;
                j++;
            }
            else
            {
                if (i > 0)
                {
                    i = lps[i - 1];
                }
                else
                {
                    lps[j] = 0;
                    j++;
                }
            }
        }

        return lps[s.size() - 1];
    }
};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        string str;
        cin >> str;

        Solution ob;

        cout << ob.lps(str) << "\n";
    }

    return 0;
}