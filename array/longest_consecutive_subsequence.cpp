/**
 * @file longest_consecutive_subsequence.cpp
 * @author Arunangshu Biswas (arunangshubsws@gmail.com)
 * @brief https://practice.geeksforgeeks.org/problems/longest-consecutive-subsequence2449/1
 * @version 0.1
 * @date 2020-11-15
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include <bits/stdc++.h>
using namespace std;

int findLongestConseqSubseq(int arr[], int n);

// Driver program
int main()
{
    int t, n, i, a[100001];
    cin >> t;
    while (t--)
    {
        cin >> n;
        for (i = 0; i < n; i++)
            cin >> a[i];
        cout << findLongestConseqSubseq(a, n) << endl;
    }

    return 0;
}

// arr[] : the input array
// N : size of the array arr[]
// return the length of the longest subsequene of consecutive integers
int findLongestConseqSubseq(int arr[], int N)
{
    unordered_set<int> s;

    for (int i = 0; i < N; i++)
    {
        s.insert(arr[i]);
    }

    int longest = 0;
    for (int i = 0; i < N; i++)
    {
        if (s.find(arr[i] - 1) == s.end())
        {
            int count = 1;
            int current = arr[i];
            while (s.find(current + 1) != s.end())
            {
                current = current + 1;
                count++;
            }
            longest = max(longest, count);
        }
    }

    return longest;
}