/**
 * @file maximum_product_subarray.cpp
 * @author Arunangshu Biswas (arunangshubsws@gmail.com)
 * @brief https://practice.geeksforgeeks.org/problems/maximum-product-subarray3604/1
 * @version 0.1
 * @date 2020-11-15
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include <bits/stdc++.h>
using namespace std;

//User function template for C++
class Solution{
public:

	// Function to find maximum product subarray
	long long maxProduct(int *arr, int n) {
	    long long maxProduct = 1, minProduct = 1, result = 1;

        for (int i = 0; i < n; i++) {
            if (arr[i] < 0)
                swap(maxProduct, minProduct);

            maxProduct = max((long long) arr[i], arr[i] * maxProduct);
            minProduct = min((long long) arr[i], arr[i] * minProduct);

            result = max(result, maxProduct);
        }

        return result;
	}
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.maxProduct(arr, n);
        cout << ans << "\n";
    }
    return 0;
}