/**
 * @file subarray_with_zero_sum.cpp
 * @author Arunangshu Biswas (arunangshubsws@gmail.com)
 * @brief https://practice.geeksforgeeks.org/problems/subarray-with-0-sum-1587115621/1
 * @version 0.1
 * @date 2020-11-15
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include <bits/stdc++.h>
using namespace std;

bool subArrayExists(int arr[], int n);

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        if (subArrayExists(arr, n))
            cout << "Yes\n";
        else
            cout << "No\n";
    }
    return 0;
}

//Complete this function
bool subArrayExists(int arr[], int n)
{
    unordered_set<int> s;

    int cumulativeSum = 0;
    for (int i = 0; i < n; i++)
    {
        cumulativeSum += arr[i];

        if (cumulativeSum == 0 || s.find(cumulativeSum) != s.end())
            return true;

        s.insert(cumulativeSum);
    }

    return false;
}