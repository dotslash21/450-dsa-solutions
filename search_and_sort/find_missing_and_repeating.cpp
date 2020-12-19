/**
 * @file find_missing_and_repeating.cpp
 * @author Arunangshu Biswas (arunangshubsws@gmail.com)
 * @brief https://practice.geeksforgeeks.org/problems/find-missing-and-repeating2512/1
 * @version 0.1
 * @date 2020-12-19
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int *findTwoElement(int *arr, int n)
    {
        int *res = (int *)malloc(2 * sizeof(int));

        for (int i = 0; i < n; i++)
        {
            while (arr[i] != i + 1)
            {
                if (arr[i] == arr[arr[i] - 1])
                {
                    res[0] = arr[i];
                    break;
                }

                swap(arr[i], arr[arr[i] - 1]);
            }
        }

        res[1] = 1;
        for (int i = 0; i < n; i++)
        {
            if (res[1] == arr[i])
                res[1]++;
        }

        return res;
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findTwoElement(a, n);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}