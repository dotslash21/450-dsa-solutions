/**
 * @file find_pair_given_difference.cpp
 * @author Arunangshu Biswas (arunangshubsws@gmail.com)
 * @brief https://practice.geeksforgeeks.org/problems/find-pair-given-difference/0#
 * @version 0.1
 * @date 2020-12-19
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include <bits/stdc++.h>
using namespace std;

bool hasPair(vector<int> arr, int k)
{
    if (arr.size() <= 1)
        return false;

    sort(arr.begin(), arr.end());

    int i = 0;
    int j = 1;
    while (j < arr.size())
    {
        int diff = arr[j] - arr[i];

        if (diff == k)
        {
            return true;
        }
        else if (diff < k)
        {
            j++;
        }
        else if (diff > k && i + 1 < j)
        {
            i++;
        }
        else
        {
            i++;
            j++;
        }
    }

    return false;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        cout << (hasPair(arr, k) ? "1" : "-1") << "\n";
    }
    return 0;
}