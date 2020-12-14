/**
 * @file min_operations.cpp
 * @author Arunangshu Biswas (arunangshubsws@gmail.com)
 * @brief https://www.geeksforgeeks.org/transform-one-string-to-another-using-minimum-number-of-given-operation/
 * @version 0.1
 * @date 2020-12-14
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include <bits/stdc++.h>
using namespace std;

int minOperations(string s1, string s2)
{
    int m = s1.size(), n = s2.size();

    int count[256];

    memset(count, 0, sizeof(count));

    for (int i = 0; i < m; i++)
        count[i]++;
    for (int i = 0; i < n; i++)
        count[i]--;
    for (int i = 0; i < 256; i++)
        if (count[i] != 0)
            return -1;

    int res = 0;
    for (int i = m - 1, j = n - 1; i >= 0;)
    {
        while (i >= 0 && s1[i] != s2[j])
        {
            res++;
            i--;
        }

        if (i >= 0)
        {
            i--;
            j--;
        }
    }

    return res;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s1, s2;
        cin >> s1 >> s2;
        cout << minOperations(s1, s2) << "\n";
    }
}