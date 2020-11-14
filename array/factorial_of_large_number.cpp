/**
 * @file factorial_of_large_number.cpp
 * @author Arunangshu Biswas (arunangshubsws@gmail.com)
 * @brief https://practice.geeksforgeeks.org/problems/factorials-of-large-numbers/0
 * @version 0.1
 * @date 2020-11-15
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include <bits/stdc++.h>
using namespace std;

void multiply(int n, vector<int>& result) {
    if (n == 0) {
        result.resize(1);
        result[0] = 0;
        return;
    }

    if (n == 1) {
        return;
    }

    int carry = 0;
    for (int i = 0; i < result.size(); i++) {
        int num = result[i];
        num *= n;
        num += carry;
        result[i] = num % 10;
        carry = num / 10;
    }

    while (carry > 0) {
        result.push_back(carry % 10);
        carry /= 10;
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> result{1};

        for (int i = n; i >= 2; i--) {
            multiply(i, result);
        }

        reverse(result.begin(), result.end());
        for (int i = 0; i < result.size(); i++) {
            cout << result[i];
        }
        cout << "\n";
    }

    return 0;
}