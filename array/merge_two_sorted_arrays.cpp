/**
 * @file merge_two_sorted_arrays.cpp
 * @author Arunangshu Biswas (arunangshubsws@gmail.com)
 * @brief https://practice.geeksforgeeks.org/problems/merge-two-sorted-arrays5135/1
 * @version 0.1
 * @date 2020-11-13
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include <bits/stdc++.h>
using namespace std;

//User function template for C++
class Solution
{
public:
    void merge(int arr1[], int arr2[], int n, int m)
    {
        int i = n - 1;
        int j = 0;

        while(i > -1 && j < m) {
            if (arr1[i] > arr2[j])
                swap(arr1[i], arr2[j]);
            else
                break;
            
            i--;
            j++;
        }

        sort(arr1, arr1 + n);
        sort(arr2, arr2 + m);
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m, i;
        cin >> n >> m;
        int arr1[n], arr2[m];
        for (i = 0; i < n; i++)
        {
            cin >> arr1[i];
        }
        for (i = 0; i < m; i++)
        {
            cin >> arr2[i];
        }
        Solution ob;
        ob.merge(arr1, arr2, n, m);
        for (i = 0; i < n; i++)
        {
            cout << arr1[i] << " ";
        }
        for (i = 0; i < m; i++)
        {
            cout << arr2[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}