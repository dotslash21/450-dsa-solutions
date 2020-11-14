/**
 * @file alternative_positive_negative.cpp
 * @author Arunangshu Biswas (arunangshubsws@gmail.com)
 * @brief https://www.geeksforgeeks.org/rearrange-array-alternating-positive-negative-items-o1-extra-space/
 * @version 0.1
 * @date 2020-11-15
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include <bits/stdc++.h>
using namespace std;

void rotate(int i, int j, vector<int>& arr) {
    if (i > j || i < 0 || j >= arr.size()) {
        throw invalid_argument("Error: Invalid index");
    }

    for (int idx = j; idx > i; idx--) {
        swap(arr[idx], arr[idx - 1]);
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        for (int i = 0; i < n; i++) {
            if (i % 2 == 0 && arr[i] >= 0) {
                int j = i + 1;
                while (j < n && arr[j] >= 0) j++;

                if (j == n) break;

                rotate(i, j, arr);
            }

            if (i % 2 == 1 && arr[i] < 0) {
                int j = i + 1;
                while (j < n && arr[j] < 0) j++;

                if (j == n) break;

                rotate(i, j, arr);
            }
        }

        for (int i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }    

    return 0;
}