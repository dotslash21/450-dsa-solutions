/**
 * @file minimize_the_heights.cpp
 * @author Arunangshu Biswas (arunangshubsws@gmail.com)
 * @brief https://practice.geeksforgeeks.org/problems/minimize-the-heights3351/1#
 * @version 0.1
 * @date 2020-11-24
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int getMinDiff(int arr[], int n, int k)
    {
        vector<pair<int, int>> v;
        vector<int> taken(n);

        for (int i = 0; i < n; i++)
        {
            if (arr[i] - k >= 0)
            {
                v.push_back({arr[i] - k, i});
            }
            v.push_back({arr[i] + k, i});
        }

        sort(v.begin(), v.end());

        int elements_in_range = 0;
        int left = 0;
        int right = 0;

        while (elements_in_range < n && right < v.size())
        {
            if (taken[v[right].second] == 0)
            {
                elements_in_range++;
            }
            taken[v[right].second]++;
            right++;
        }

        int ans = v[right - 1].first - v[left].first;

        while (right < v.size())
        {
            if (taken[v[left].second] == 1)
            {
                elements_in_range--;
            }
            taken[v[left].second]--;
            left++;

            while (elements_in_range < n && right < v.size())
            {
                if (taken[v[right].second] == 0)
                {
                    elements_in_range++;
                }
                taken[v[right].second]++;
                right++;
            }

            if (elements_in_range == n)
            {
                ans = min(ans, v[right - 1].first - v[left].first);
            }
            else
            {
                break;
            }
        }

        return ans;
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> k;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.getMinDiff(arr, n, k);
        cout << ans << "\n";
    }
    return 0;
}