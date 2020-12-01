/**
 * @file longest_common_prefix.cpp
 * @author Arunangshu Biswas (arunangshubsws@gmail.com)
 * @brief https://leetcode.com/problems/longest-common-prefix/
 * @version 0.1
 * @date 2020-12-01
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string longestCommonPrefix(vector<string> &strs)
    {
        if (strs.size() == 0)
            return "";

        string prefix = "";

        int idx = 0;
        while (true)
        {
            int count = 0;

            for (int i = 0; i < strs.size(); i++)
            {
                if (idx < strs[i].size() && strs[i][idx] == strs[0][idx])
                    count++;
            }

            if (count != strs.size())
                break;

            prefix.push_back(strs[0][idx]);
            idx++;
        }

        return prefix;
    }
};