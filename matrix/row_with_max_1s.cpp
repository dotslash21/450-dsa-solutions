/**
 * @file row_with_max_1s.cpp
 * @author Arunangshu Biswas (arunangshubsws@gmail.com)
 * @brief https://practice.geeksforgeeks.org/problems/row-with-max-1s0023/1#
 * @version 0.1
 * @date 2020-11-19
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
    int firstOne(vector<int> &arr, int m)
    {
        if (arr[m - 1] == 0)
            return -1;

        int lo = 0;
        int hi = m - 1;
        while (lo <= hi)
        {
            int mid = lo + (hi - lo) / 2;

            if ((mid == 0 || arr[mid - 1] == 0) && arr[mid] == 1)
            {
                return mid;
            }
            else if (arr[mid] == 0)
            {
                lo = mid + 1;
            }
            else
            {
                hi = mid - 1;
            }
        }

        return -1;
    }

    int rowWithMax1s(vector<vector<int>> matrix, int n, int m)
    {
        if (n == 0)
            return -1;

        int row = 0;
        int index = firstOne(matrix[row], m);
        while (index == -1 && row < n - 1)
        {
            index = firstOne(matrix[++row], m);
        }

        for (int i = row + 1; i < n; i++)
        {
            if (index == 0 || index == -1)
                break;

            if (matrix[i][index] == 0 || matrix[i][index - 1] == 0)
                continue;

            index = firstOne(matrix[i], m);
            row = i;
        }

        return index == -1 ? -1 : row;
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> arr(n, vector<int>(m));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> arr[i][j];
            }
        }
        Solution ob;
        auto ans = ob.rowWithMax1s(arr, n, m);
        cout << ans << "\n";
    }
    return 0;
}