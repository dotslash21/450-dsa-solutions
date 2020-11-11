/**
 * @file union_of_two_arrays.cpp
 * @author Arunangshu Biswas (arunangshubsws@gmail.com)
 * @brief https://practice.geeksforgeeks.org/problems/union-of-two-arrays/0#
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
        int n, m;
        cin >> n >> m;
        int a[n], b[m];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        for (int i = 0; i < m; i++) {
            cin >> b[i];
        }

        unordered_set<int> set;

        for (int i = 0; i < n; i++) {
            set.insert(a[i]);
        }
        for (int i = 0; i < m; i++) {
            set.insert(b[i]);
        }

        cout << set.size() << endl;
    }

    return 0;
}