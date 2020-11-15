/**
 * @file array_subset_of_another_array.cpp
 * @author Arunangshu Biswas (arunangshubsws@gmail.com)
 * @brief https://practice.geeksforgeeks.org/problems/array-subset-of-another-array/0#
 * @version 0.1
 * @date 2020-11-16
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include <bits/stdc++.h>
using namespace std;

bool isSubset(int arr1[], int m, int arr2[], int n)
{
    if (m < n)
        return false;

    unordered_map<int, int> count;
    for (int i = 0; i < m; i++)
    {
        count[arr1[i]]++;
    }

    for (int i = 0; i < n; i++)
    {
        if (count[arr2[i]] > 0)
        {
            count[arr2[i]]--;
        }
        else
        {
            return false;
        }
    }

    return true;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int m, n;
        cin >> m >> n;
        int arr1[m], arr2[n];
        for (int i = 0; i < m; i++)
        {
            cin >> arr1[i];
        }
        for (int i = 0; i < n; i++)
        {
            cin >> arr2[i];
        }

        if (isSubset(arr1, m, arr2, n))
            cout << "Yes\n";
        else
            cout << "No\n";
    }

    return 0;
}