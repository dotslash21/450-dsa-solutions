/**
 * @file next_permutation.cpp
 * @author Arunangshu Biswas (arunangshubsws@gmail.com)
 * @brief https://practice.geeksforgeeks.org/problems/next-permutation/0
 * @version 0.1
 * @date 2020-11-24
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include <bits/stdc++.h>
using namespace std;

int findLowestGreater(int arr[], int start, int end, int value)
{
    int lo = start;
    int hi = end - 1;

    while (lo < hi)
    {
        int mid = lo + ceil((hi - lo) / 2.0);

        if (arr[mid] > value)
        {
            lo = mid;
        }
        else
        {
            hi = mid - 1;
        }
    }

    return hi;
}

void next_permutation(int arr[], int n)
{
    int idx = n - 2;
    while (idx > -1 && arr[idx] > arr[idx + 1])
        idx--;

    if (idx == -1)
    {
        reverse(arr, arr + n);
        return;
    }

    int replace = findLowestGreater(arr, idx + 1, n, arr[idx]);

    swap(arr[idx], arr[replace]);

    reverse(arr + idx + 1, arr + n);
}

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

        next_permutation(arr, n);

        for (int i = 0; i < n; i++)
            cout << arr[i] << " ";
        cout << "\n";
    }

    return 0;
}