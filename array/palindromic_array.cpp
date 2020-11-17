/**
 * @file palindromic_array.cpp
 * @author Arunangshu Biswas (arunangshubsws@gmail.com)
 * @brief https://practice.geeksforgeeks.org/problems/palindromic-array-1587115620/1#
 * @version 0.1
 * @date 2020-11-17
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include <iostream>
#include <string.h>
using namespace std;

int PalinArray(int a[], int n);

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
            cin >> a[i];
        cout << PalinArray(a, n) << endl;
    }
}

bool isPalindromeNumber(int n)
{
    int original = n;
    int reverse = 0;
    while (n > 0)
    {
        reverse = (reverse * 10) + (n % 10);
        n = n / 10;
    }

    return (original == reverse);
}

/*Complete the function below*/
int PalinArray(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        if (!isPalindromeNumber(a[i]))
            return 0;
    }

    return 1;
}