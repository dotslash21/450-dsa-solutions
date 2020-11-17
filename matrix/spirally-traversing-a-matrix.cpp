/**
 * @file spirally-traversing-a-matrix.cpp
 * @author Arunangshu Biswas (arunangshubsws@gmail.com)
 * @brief https://practice.geeksforgeeks.org/problems/spirally-traversing-a-matrix-1587115621/1#
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
    vector<int> spirallyTraverse(vector<vector<int>> matrix, int r, int c)
    {
        vector<int> result;

        int rs = 0, re = r - 1;
        int cs = 0, ce = c - 1;
        while (rs <= re && cs <= ce)
        {
            // Top - left to right
            for (int i = cs; i <= ce; i++)
            {
                result.push_back(matrix[rs][i]);
            }
            rs++;

            // Right - top to bottom
            for (int i = rs; i <= re; i++)
            {
                result.push_back(matrix[i][ce]);
            }
            ce--;

            // Bottom - right to left
            if (rs <= re)
            {
                for (int i = ce; i >= cs; i--)
                {
                    result.push_back(matrix[re][i]);
                }
                re--;
            }

            // Left - bottom to top
            if (cs <= ce)
            {
                for (int i = re; i >= rs; i--)
                {
                    result.push_back(matrix[i][cs]);
                }
                cs++;
            }
        }

        return result;
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
        vector<vector<int>> matrix(r);

        for (int i = 0; i < r; i++)
        {
            matrix[i].assign(c, 0);
            for (int j = 0; j < c; j++)
            {
                cin >> matrix[i][j];
            }
        }

        Solution ob;
        vector<int> result = ob.spirallyTraverse(matrix, r, c);
        for (int i = 0; i < result.size(); ++i)
            cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}