/**
 * @file find_all_duplicates_in_string.cpp
 * @author Arunangshu Biswas (arunangshubsws@gmail.com)
 * @brief https://www.geeksforgeeks.org/print-all-the-duplicates-in-the-input-string/
 * @version 0.1
 * @date 2020-11-20
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include <bits/stdc++.h>
using namespace std;

void printDuplicate(string s)
{
    unordered_map<char, int> mp;

    for (char c : s)
    {
        mp[c]++;
    }

    for (auto it : mp)
    {
        if (it.second > 1)
            cout << it.first << " ";
    }
    cout << "\n";
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin.ignore();
        getline(cin, s);
        printDuplicate(s);
    }

    return 0;
}