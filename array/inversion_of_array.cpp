/**
 * @file inversion_of_array.cpp
 * @author Arunangshu Biswas (arunangshubsws@gmail.com)
 * @brief https://www.geeksforgeeks.org/counting-inversions/
 * @version 0.1
 * @date 2020-11-13
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include <bits/stdc++.h>
using namespace std;

long long int merge(long long arr1[], long long arr2[], long long n, long long m)
{
    long long int inversions = 0;
    long long int arr3[n + m];

    long long last = 0, i = 0, j = 0;
    while(i < n && j < m) {
        if (arr1[i] <= arr2[j]) {
            arr3[last++] = arr1[i++];
        } else {
            inversions += (n - i);
            arr3[last++] = arr2[j++];
        }
    }

    while (i < n)
        arr3[last++] = arr1[i++];

    while (j < m)
        arr3[last++] = arr2[j++];

    // copy back to original aarray
    copy(arr3, arr3 + n + m, arr1);

    return inversions;
}

// Function to find inversion count in the array
// arr[]: Input Array
// N : Size of the Array arr[]
long long int inversionCount(long long arr[], long long N)
{
    if (N <= 1)
        return 0;

    // Divide
    long long mid = N / 2;
    long long inversions = inversionCount(arr, mid) + inversionCount(arr + mid, N - mid);

    // Conquer
    inversions += merge(arr, arr + mid, mid, N - mid);

    return inversions;
}

int main() {
    
    long long T;
    cin >> T;
    
    while(T--){
        long long N;
        cin >> N;
        
        long long A[N];
        for(long long i = 0;i<N;i++){
            cin >> A[i];
        }
        
        cout << inversionCount(A,N) << endl;
    }
    
    return 0;
}