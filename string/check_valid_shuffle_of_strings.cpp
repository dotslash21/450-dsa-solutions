/**
 * @file check_valid_shuffle_of_strings.cpp
 * @author Arunangshu Biswas (arunangshubsws@gmail.com)
 * @brief https://www.programiz.com/java-programming/examples/check-valid-shuffle-of-strings
 * @version 0.1
 * @date 2020-11-20
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include <bits/stdc++.h>
using namespace std;

bool isValidShuffle(string s1, string s2, string shuffle)
{
    if (s1.size() + s2.size() != shuffle.size())
        return false;

    int i = 0, j = 0;
    for (char c : shuffle)
    {
        if (i < s1.size() && c == s1[i])
        {
            i++;
        }
        else if (j < s2.size() && c == s2[j])
        {
            j++;
        }
        else
        {
            return false;
        }
    }

    return true;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s1, s2, shuffle;
        cin >> s1;
        cin >> s2;
        cin >> shuffle;
        cout << (isValidShuffle(s1, s2, shuffle) ? "YES" : "NO") << "\n";
    }

    return 0;
}