/**
 * @file reverse_string.cpp
 * @author Arunangshu Biswas (arunangshubsws@gmail.com)
 * @brief https://leetcode.com/problems/reverse-string/
 * @version 0.1
 * @date 2020-11-20
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void reverseString(vector<char> &s)
    {
        int n = s.size();
        for (int i = 0; i < n / 2; i++)
        {
            swap(s[i], s[n - i - 1]);
        }
    }
};