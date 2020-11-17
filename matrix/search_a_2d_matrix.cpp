/**
 * @file search_a_2d_matrix.cpp
 * @author Arunangshu Biswas (arunangshubsws@gmail.com)
 * @brief https://leetcode.com/problems/search-a-2d-matrix/
 * @version 0.1
 * @date 2020-11-17
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        int m = matrix.size();
        if (m == 0)
            return false;

        int n = matrix[0].size();
        if (n == 0)
            return false;

        int lo = 0;
        int hi = matrix.size() - 1;
        while (lo <= hi)
        {
            int mid = (lo + hi) / 2;

            if (target < matrix[mid][0])
            {
                hi = mid - 1;
            }
            else if (target > matrix[mid][matrix[mid].size() - 1])
            {
                lo = mid + 1;
            }
            else
            {
                return binary_search(matrix[mid].begin(), matrix[mid].end(), target);
            }
        }

        return false;
    }
};