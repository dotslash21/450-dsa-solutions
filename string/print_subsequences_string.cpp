/**
 * @file print_subsequences_string.cpp
 * @author Arunangshu Biswas (arunangshubsws@gmail.com)
 * @brief https://www.geeksforgeeks.org/print-subsequences-string/
 * @version 0.1
 * @date 2020-11-22
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include <bits/stdc++.h>
using namespace std;

void printSubsequences(string s, int n, int index = 0, string curr = "")
{
    if (curr.size() > 0)
        cout << curr << "\n";

    for (int i = index; i < n; i++)
    {
        curr += s[i];

        printSubsequences(s, n, i + 1, curr);

        curr.erase(curr.size() - 1);
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        string s;
        cin >> s;

        printSubsequences(s, n);
    }

    return 0;
}