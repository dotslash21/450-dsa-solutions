/**
 * @file find_the_median.cpp
 * @author Arunangshu Biswas (arunangshubsws@gmail.com)
 * @brief https://practice.geeksforgeeks.org/problems/find-the-median0527/1
 * @version 0.1
 * @date 2020-11-17
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int find_median(vector<int> v)
    {
        sort(v.begin(), v.end());

        int n = v.size();
        int mid = n / 2;

        if (n % 2 == 0)
        {
            return (v[mid] + v[mid - 1]) / 2;
        }
        else
        {
            return v[mid];
        }
    }
};

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int n;
        cin >> n;
        vector<int> v(n);
        for (int i = 0; i < n; i++)
            cin >> v[i];
        Solution ob;
        int ans = ob.find_median(v);
        cout << ans << "\n";
    }
    return 0;
}