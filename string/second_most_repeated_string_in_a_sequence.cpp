/**
 * @file second_most_repeated_string_in_a_sequence.cpp
 * @author Arunangshu Biswas (arunangshubsws@gmail.com)
 * @brief https://practice.geeksforgeeks.org/problems/second-most-repeated-string-in-a-sequence0534/1#
 * @version 0.1
 * @date 2020-12-02
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string secFrequent(string arr[], int n)
    {
        unordered_map<string, int> mp;

        // Insert into the map
        for (int i = 0; i < n; i++)
        {
            mp[arr[i]]++;
        }

        // Find the second max
        string maxStr = "";
        int maxCount = -1;
        string secondMaxStr = "";
        int secondMaxCount = -1;
        for (pair<string, int> it : mp)
        {
            if (it.second > maxCount)
            {
                secondMaxStr = maxStr;
                secondMaxCount = maxCount;
                maxStr = it.first;
                maxCount = it.second;
            }
            else if (it.second > secondMaxCount)
            {
                secondMaxStr = it.first;
                secondMaxCount = it.second;
            }
        }

        return secondMaxStr;
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
        string arr[n];
        for (int i = 0; i < n; ++i)
            cin >> arr[i];
        Solution ob;
        cout << ob.secFrequent(arr, n) << endl;
    }
}