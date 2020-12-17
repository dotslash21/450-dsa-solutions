/**
 * @file first_and_last_occurrences_of_x.cpp
 * @author Arunangshu Biswas (arunangshubsws@gmail.com)
 * @brief https://practice.geeksforgeeks.org/problems/first-and-last-occurrences-of-x/0
 * @version 0.1
 * @date 2020-12-17
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include <bits/stdc++.h>
using namespace std;

int get_first_occurrence(vector<int> &arr, int n, int k)
{
    int lo = 0, hi = n - 1;
    while (lo < hi)
    {
        int mid = lo + (hi - lo) / 2;

        if (arr[mid] >= k)
        {
            hi = mid;
        }
        else
        {
            lo = mid + 1;
        }
    }

    if (arr[lo] != k)
        return -1;

    return lo;
}

int get_last_occurrence(vector<int> &arr, int n, int k)
{
    int lo = 0, hi = n - 1;
    while (lo < hi)
    {
        int mid = lo + ceil((double)(hi - lo) / 2.0);

        if (arr[mid] > k)
        {
            hi = mid - 1;
        }
        else
        {
            lo = mid;
        }
    }

    if (arr[lo] != k)
        return -1;

    return lo;
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
            cin >> arr[i];
        int first = get_first_occurrence(arr, n, k);
        int last = get_last_occurrence(arr, n, k);
        if (first != -1 && last != -1)
            cout << first << " " << last << "\n";
        else
            cout << "-1\n";
    }
    return 0;
}