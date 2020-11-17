/**
 * @file median_two_sorted_arrays_different_sizes.cpp
 * @author Arunangshu Biswas (arunangshubsws@gmail.com)
 * @brief https://www.geeksforgeeks.org/median-of-two-sorted-arrays-of-different-sizes/
 * @version 0.1
 * @date 2020-11-17
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include <bits/stdc++.h>
using namespace std;

double findMedian(int arr1[], int m, int arr2[], int n)
{
    if (m > n)
        return findMedian(arr2, n, arr1, m);

    int lo = 0;
    int hi = m;
    int size = m + n;
    while (lo <= hi)
    {
        // Calculate the partitions
        int i = (lo + hi) / 2;
        int j = ((size + 1) / 2) - i;

        // Handle the boundary conditions
        int maxLeft1 = (i == 0) ? INT_MIN : arr1[i - 1];
        int minRight1 = (i == m) ? INT_MAX : arr1[i];
        int maxLeft2 = (j == 0) ? INT_MIN : arr2[j - 1];
        int minRight2 = (j == n) ? INT_MAX : arr2[j];

        if (minRight1 > maxLeft2 && maxLeft1 < minRight2)
        {
            if (size % 2 == 0)
            {
                return (max(maxLeft1, maxLeft2) + min(minRight1, minRight2)) / 2.0;
            }
            else
            {
                return max(maxLeft1, maxLeft2);
            }
        }
        else if (minRight1 < maxLeft2)
        {
            lo = i + 1;
        }
        else
        {
            hi = i - 1;
        }
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int m;
        cin >> m;
        int arr1[m];
        for (int i = 0; i < m; i++)
            cin >> arr1[i];
        int n;
        cin >> n;
        int arr2[n];
        for (int i = 0; i < n; i++)
            cin >> arr2[i];
        cout << findMedian(arr1, m, arr2, n) << "\n";
    }

    return 0;
}