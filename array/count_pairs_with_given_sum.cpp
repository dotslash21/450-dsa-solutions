/**
 * @file count_pairs_with_given_sum.cpp
 * @author Arunangshu Biswas (arunangshubsws@gmail.com)
 * @brief https://practice.geeksforgeeks.org/problems/count-pairs-with-given-sum5022/1#
 * @version 0.1
 * @date 2020-11-14
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int getPairsCount(int arr[], int n, int k)
    {
        int numPairs = 0;
        unordered_map<int, int> m;

        for (int i = 0; i < n; i++)
        {
            if (m.find(k - arr[i]) != m.end())
            {
                numPairs += m[k - arr[i]];
            }
            m[arr[i]]++;
        }

        return numPairs;
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.getPairsCount(arr, n, k);
        cout << ans << "\n";
    }

    return 0;
}