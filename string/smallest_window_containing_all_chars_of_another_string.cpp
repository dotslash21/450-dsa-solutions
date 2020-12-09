/**
 * @file smallest_window_containing_all_chars_of_another_string.cpp
 * @author Arunangshu Biswas (arunangshubsws@gmail.com)
 * @brief https://practice.geeksforgeeks.org/problems/smallest-window-in-a-string-containing-all-the-characters-of-another-string-1587115621/1#
 * @version 0.1
 * @date 2020-12-09
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include <bits/stdc++.h>
using namespace std;

// return the smallest window in S with all the characters of P
// if no such window exists, return "-1"
string smallestWindow(string S, string P)
{
    int m = S.size();
    int n = P.size();
    if (m < n)
    {
        cout << "-1";
        return "";
    }

    int hash_pat[256] = {0};
    int hash_str[256] = {0};

    for (char c : P)
        hash_pat[c]++;

    int start = 0, start_index = -1, min_length = INT_MAX;

    int count = 0;
    for (int i = 0; i < m; i++)
    {
        hash_str[S[i]]++;

        if (hash_pat[S[i]] != 0 && hash_str[S[i]] <= hash_pat[S[i]])
            count++;

        if (count == n)
        {
            while (hash_str[S[start]] > hash_pat[S[start]] || hash_pat[S[start]] == 0)
            {
                if (hash_str[S[start]] > hash_pat[S[start]])
                    hash_str[S[start]]--;
                start++;
            }

            int len_window = i - start + 1;
            if (min_length > len_window)
            {
                min_length = len_window;
                start_index = start;
            }
        }
    }

    if (start_index == -1)
    {
        cout << "-1";
        return "";
    }

    return S.substr(start_index, min_length);
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        string pat;
        cin >> pat;

        cout << smallestWindow(s, pat) << endl;
    }
    return 0;
}