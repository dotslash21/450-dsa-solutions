/**
 * @file permutations_of_given_string.cpp
 * @author Arunangshu Biswas (arunangshubsws@gmail.com)
 * @brief https://practice.geeksforgeeks.org/problems/permutations-of-a-given-string/0
 * @version 0.1
 * @date 2020-11-22
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include <bits/stdc++.h>
using namespace std;

void printPermutations(string s, string permutation = "")
{
    if (permutation.size() == s.size())
        cout << permutation << " ";

    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == 32)
            continue;

        char curr = s[i];
        s[i] = 32;
        permutation.push_back(curr);

        printPermutations(s, permutation);

        permutation.erase(permutation.size() - 1);
        s[i] = curr;
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        sort(s.begin(), s.end());
        printPermutations(s);
        cout << "\n";
    }

    return 0;
}