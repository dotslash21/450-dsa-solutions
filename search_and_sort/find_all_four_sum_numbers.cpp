/**
 * @file find_all_four_sum_numbers.cpp
 * @author Arunangshu Biswas (arunangshubsws@gmail.com)
 * @brief https://practice.geeksforgeeks.org/problems/find-all-four-sum-numbers1732/1#
 * @version 0.1
 * @date 2020-12-19
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> fourSum(vector<int> &a, int k);

// Position this line where user code will be pasted.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k, i;
        cin >> n >> k;
        vector<int> a(n);
        for (i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        vector<vector<int>> ans = fourSum(a, k);
        for (auto &v : ans)
        {
            for (int &u : v)
            {
                cout << u << " ";
            }
            cout << "$";
        }
        if (ans.empty())
        {
            cout << -1;
        }
        cout << "\n";
    }
    return 0;
}

// User function template for C++

// arr[] : int input array of integers
// k : the quadruple sum required
vector<vector<int>> fourSum(vector<int> &arr, int s)
{
    vector<vector<int>> result;

    sort(arr.begin(), arr.end());

    for (int i = 0; i < arr.size() - 3; i++)
    {
        if (i > 0 && arr[i] == arr[i - 1])
            continue;

        for (int j = i + 1; j < arr.size() - 2; j++)
        {
            if (j > i + 1 && arr[j] == arr[j - 1])
                continue;

            int k = j + 1;
            int l = arr.size() - 1;

            while (k < l)
            {
                int prev_k = k;
                int prev_l = l;

                int sum = arr[i] + arr[j] + arr[k] + arr[l];

                if (sum == s)
                {
                    result.push_back({arr[i], arr[j], arr[k], arr[l]});

                    while (k < l && arr[prev_k] == arr[k])
                        k++;
                    while (k < l && arr[prev_l] == arr[l])
                        l--;
                }
                else if (sum < s)
                {
                    k++;
                }
                else
                {
                    l--;
                }
            }
        }
    }

    return result;
}