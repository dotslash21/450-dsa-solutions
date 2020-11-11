/**
 * @file cyclically_rotate_array_by_one.cpp
 * @author Arunangshu Biswas (arunangshubsws@gmail.com)
 * @brief https://practice.geeksforgeeks.org/problems/cyclically-rotate-an-array-by-one/0#
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
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        int last = arr[n - 1];
        for (int i = n - 1; i > 0; i--) {
            arr[i] = arr[i - 1];
        }
        arr[0] = last;

        for (int i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }

    return 0;
}