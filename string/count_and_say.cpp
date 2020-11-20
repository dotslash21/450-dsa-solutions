/**
 * @file count_and_say.cpp
 * @author Arunangshu Biswas (arunangshubsws@gmail.com)
 * @brief https://leetcode.com/problems/count-and-say/
 * @version 0.1
 * @date 2020-11-21
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string getNext(string s)
    {
        string result = "";

        int i = 0;
        while (i < s.size())
        {
            int j = i + 1;
            while (j < s.size() && s[j] == s[i])
            {
                j++;
            }

            result.append(to_string(j - i));
            result.push_back(s[i]);

            i = j;
        }

        return result;
    }

    string countAndSay(int n)
    {
        string result = "1";

        for (int i = 2; i <= n; i++)
        {
            result = getNext(result);
        }

        return result;
    }
};