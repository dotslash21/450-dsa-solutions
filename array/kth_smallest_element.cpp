/**
 * @file kth_smallest_element.cpp
 * @author Arunangshu Biswas (arunangshubsws@gmail.com)
 * @brief https://practice.geeksforgeeks.org/problems/kth-smallest-element5635/1#
 * @version 0.1
 * @date 2020-11-11
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include <bits/stdc++.h>
using namespace std;

int kthSmallest(int *, int, int, int);

int main()
{
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);

    int test_case;
    cin >> test_case;
    while (test_case--)
    {
        int number_of_elements;
        cin >> number_of_elements;
        int a[number_of_elements];

        for (int i = 0; i < number_of_elements; i++)
            cin >> a[i];

        int k;
        cin >> k;
        cout << kthSmallest(a, 0, number_of_elements - 1, k) << endl;
    }
    return 0;
}

// arr : given array
// l : starting index of the array i.e 0
// r : ending index of the array i.e size-1
// k : find kth smallest element and return using this function
int kthSmallest(int arr[], int l, int r, int k)
{
    if (k > r - l + 1)
    {
        throw invalid_argument("k cannot be greater than the size of the array!");
    }

    sort(arr + l, arr + r + 1);
    
    return arr[l + k - 1];
}