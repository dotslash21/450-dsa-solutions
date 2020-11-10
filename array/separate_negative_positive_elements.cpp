/**
 * @file separate_negative_positive_elements.cpp
 * @author Arunangshu Biswas (arunangshubsws@gmail.com)
 * @brief https://www.geeksforgeeks.org/move-negative-numbers-beginning-positive-end-constant-extra-space/
 * @version 0.1
 * @date 2020-11-11
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int i = 0;
    int j = n - 1;
    while (i < j) {
        if (arr[i] < 0 && arr[j] < 0) {
            i++;
        }
        else if (arr[i] > 0 && arr[j] < 0) {
            int temp = arr[j];
            arr[j] = arr[i];
            arr[i] = temp;
            i++;
            j--;
        }
        else if (arr[i] > 0 && arr[j] > 0) {
            j--;
        }
        else {
            i++;
            j--;
        }
    }

    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}