/**
 * @file palindrome_string.cpp
 * @author Arunangshu Biswas (arunangshubsws@gmail.com)
 * @brief https://practice.geeksforgeeks.org/problems/palindrome-string0817/1#
 * @version 0.1
 * @date 2020-11-20
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
    int isPlaindrome(string S)
    {
        int n = S.size();

        for (int i = 0; i < n / 2; i++)
        {
            if (S[i] != S[n - i - 1])
                return false;
        }

        return true;
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
        string s;
        cin >> s;

        Solution ob;

        cout << ob.isPlaindrome(s) << "\n";
    }

    return 0;
}