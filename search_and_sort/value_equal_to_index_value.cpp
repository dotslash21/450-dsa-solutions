/**
 * @file value_equal_to_index_value.cpp
 * @author Arunangshu Biswas (arunangshubsws@gmail.com)
 * @brief https://practice.geeksforgeeks.org/problems/value-equal-to-index-value1330/1
 * @version 0.1
 * @date 2020-12-17
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
    vector<int> valueEqualToIndex(int arr[], int n)
    {
        vector<int> result;

        for (int i = 0; i < n; i++)
        {
            if (arr[i] == i + 1)
                result.push_back(i + 1);
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
        int n, i;
        cin >> n;
        int arr[n];
        for (i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.valueEqualToIndex(arr, n);
        if (ans.empty())
        {
            cout << "Not Found";
        }
        else
        {
            for (int x : ans)
            {
                cout << x << " ";
            }
        }
        cout << "\n";
    }
    return 0;
}