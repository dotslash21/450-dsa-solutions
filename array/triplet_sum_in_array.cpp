/**
 * @file triplet_sum_in_array.cpp
 * @author Arunangshu Biswas (arunangshubsws@gmail.com)
 * @brief https://practice.geeksforgeeks.org/problems/triplet-sum-in-array/0#
 * @version 0.1
 * @date 2020-11-16
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include <bits/stdc++.h>
using namespace std;

bool tripletSums(int arr[], int n, int sum)
{
    if (n < 3)
        return 0;

    sort(arr, arr + n);

    for (int i = 0; i < n - 2; i++)
    {
        int a = arr[i];

        int j = i + 1, k = n - 1;
        while (j < k)
        {
            int b = arr[j], c = arr[k];

            if ((a + b + c) == sum)
            {
                return true;
            }
            else if ((a + b + c) < sum)
            {
                j++;
            }
            else
            {
                k--;
            }
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
        int n, sum;
        cin >> n >> sum;
        int arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        cout << (tripletSums(arr, n, sum) ? 1 : 0) << "\n";
    }

    return 0;
}