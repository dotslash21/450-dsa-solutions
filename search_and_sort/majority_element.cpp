/**
 * @file majority_element.cpp
 * @author Arunangshu Biswas (arunangshubsws@gmail.com)
 * @brief https://practice.geeksforgeeks.org/problems/majority-element/0 (See Moore's Voting Algorithm)
 * @version 0.1
 * @date 2020-12-19
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include <bits/stdc++.h>
using namespace std;

// Function to find majority element in the array
// a: input array
// size: size of input array
int majorityElement(int a[], int size)
{
    if (size == 0)
    {
        return -1;
    }

    int maj_elem = a[0];
    int maj_count = 1;
    for (int i = 1; i < size; i++)
    {
        if (a[i] != maj_elem)
        {
            maj_count--;

            if (maj_count == 0)
            {
                maj_elem = a[i];
                maj_count = 1;
            }
        }
        else
        {
            maj_count++;
        }
    }

    maj_count = 0;
    for (int i = 0; i < size; i++)
    {
        if (a[i] == maj_elem)
        {
            maj_count++;
        }
    }

    if (maj_count > (size / 2))
    {
        return maj_elem;
    }
    else
    {
        return -1;
    }
}

int main()
{

    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;
        int arr[n];

        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        cout << majorityElement(arr, n) << endl;
    }

    return 0;
}