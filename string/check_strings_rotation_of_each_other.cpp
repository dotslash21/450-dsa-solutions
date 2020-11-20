/**
 * @file check_strings_rotation_of_each_other.cpp
 * @author Arunangshu Biswas (arunangshubsws@gmail.com)
 * @brief https://www.geeksforgeeks.org/a-program-to-check-if-strings-are-rotations-of-each-other/
 * @version 0.1
 * @date 2020-11-20
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include <bits/stdc++.h>
using namespace std;

vector<int> precomputeLPS(string pattern)
{
    vector<int> lps(pattern.size());
    lps[0] = 0;

    int i = 0, j = 1;
    while (j < pattern.size())
    {
        if (pattern[j] == pattern[i])
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

    return lps;
}

bool kmpSearch(string text, string pattern)
{
    vector<int> lps = precomputeLPS(pattern);

    int i = 0, j = 0;
    while (i < text.size() && j < pattern.size())
    {
        if (text[i] == pattern[j])
        {
            i++;
            j++;
        }
        else
        {
            if (j > 0)
            {
                j = lps[j - 1];
            }
            else
            {
                i++;
            }
        }
    }

    return j == pattern.size();
}

bool areRotations(string s1, string s2)
{
    if (s1.size() != s2.size())
    {
        return false;
    }

    string temp = s1 + s1;

    return kmpSearch(temp, s2);
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s1, s2;
        cin >> s1;
        cin >> s2;
        cout << (areRotations(s1, s2) ? "YES" : "NO") << "\n";
    }

    return 0;
}