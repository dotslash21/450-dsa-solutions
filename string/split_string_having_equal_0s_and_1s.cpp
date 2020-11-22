/**
 * @file split_string_having_equal_0s_and_1s.cpp
 * @author Arunangshu Biswas (arunangshubsws@gmail.com)
 * @brief https://www.geeksforgeeks.org/split-the-binary-string-into-substrings-with-equal-number-of-0s-and-1s/
 * @version 0.1
 * @date 2020-11-22
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include <bits/stdc++.h>
using namespace std;

int maxSubStrings(string s)
{
    int zeroCount = 0;
    int oneCount = 0;
    int numSubStrings = 0;

    for (char c : s)
    {
        if (c == '0')
            zeroCount++;
        else
            oneCount++;

        if (zeroCount == oneCount)
            numSubStrings++;
    }

    if (zeroCount != oneCount)
        return -1;
    else
        return numSubStrings;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;

        cout << maxSubStrings(s) << "\n";
    }
}