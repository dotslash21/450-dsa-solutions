/**
 * @file min_chars_added_front_make_str_palindrome.cpp
 * @author Arunangshu Biswas (arunangshubsws@gmail.com)
 * @brief https://www.geeksforgeeks.org/minimum-characters-added-front-make-string-palindrome/
 * @version 0.1
 * @date 2020-12-08
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include <bits/stdc++.h>
using namespace std;

vector<int> computeLPSArray(string str)
{
    int n = str.size();
    vector<int> lps(n);

    int len = 0;
    lps[0] = 0;

    int i = 1;
    while (i < n)
    {
        if (str[i] == str[len])
        {
            len++;
            lps[i] = len;
            i++;
        }
        else
        {
            if (len != 0)
            {
                len = lps[len - 1];
            }
            else
            {
                lps[i] == 0;
                i++;
            }
        }
    }

    return lps;
}

int minCharsInFrontForPalindrome(string str)
{
    string concat = str + "$";
    reverse(str.begin(), str.end());
    concat += str;
    vector<int> lps = computeLPSArray(concat);
    return (str.size() - *lps.rbegin());
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string str;
        cin >> str;
        cout << minCharsInFrontForPalindrome(str) << "\n";
    }

    return 0;
}