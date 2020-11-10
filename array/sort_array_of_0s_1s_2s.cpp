/**
 * @file sort_array_of_0s_1s_2s.cpp
 * @author Arunangshu Biswas (arunangshubsws@gmail.com)
 * @brief https://practice.geeksforgeeks.org/problems/sort-an-array-of-0s-1s-and-2s/0#
 * @version 0.1
 * @date 2020-11-11
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        // Count
        int zero = 0;
        int one = 0;
        int two = 0;
        for (int i = 0; i < n; i++) {
            if (arr[i] == 0) {
                zero++;
            }
            else if (arr[i] == 1) {
                one++;
            }
            else
            {
                two++;
            }
        }

        int i = 0;
        while (zero--) arr[i++] = 0;
        while (one--) arr[i++] = 1;
        while (two--) arr[i++] = 2;

        for (int i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }

    return 0;
}