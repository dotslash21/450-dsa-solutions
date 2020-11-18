/**
 * @file median_in_row_wise_sorted_matrix.cpp
 * @author Arunangshu Biswas (arunangshubsws@gmail.com)
 * @brief https://practice.geeksforgeeks.org/problems/median-in-a-row-wise-sorted-matrix1527/1
 * @version 0.1
 * @date 2020-11-18
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include <bits/stdc++.h>
using namespace std;

//User function template for C++

class Solution
{
public:
    int median(vector<vector<int>> &matrix, int r, int c)
    {
        int min = INT_MAX, max = INT_MIN;
        for (int i = 0; i < r; i++)
        {
            min = std::min(min, matrix[i][0]);
            max = std::max(max, matrix[i][c - 1]);
        }

        int target = (r * c + 1) / 2;
        while (min < max)
        {
            int mid = min + (max - min) / 2;
            int count = 0;

            for (int i = 0; i < r; i++)
                count += upper_bound(matrix[i].begin(), matrix[i].end(), mid) - matrix[i].begin();

            if (count < target)
                min = mid + 1;
            else
                max = mid;
        }

        return min;
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int r, c;
        cin >> r >> c;
        vector<vector<int>> matrix(r, vector<int>(c));
        for (int i = 0; i < r; ++i)
            for (int j = 0; j < c; ++j)
                cin >> matrix[i][j];
        Solution obj;
        cout << obj.median(matrix, r, c) << endl;
    }
    return 0;
}