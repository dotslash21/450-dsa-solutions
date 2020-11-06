/**
 * @file fractional_knapsack.cpp
 * @author Arunangshu Biswas (arunangshubsws@gmail.com)
 * @brief https://www.geeksforgeeks.org/fractional-knapsack-problem/
 * @version 0.1
 * @date 2020-11-06
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include <bits/stdc++.h>
using namespace std;

struct Item
{
    int value;
    int weight;
};

bool compare(Item& a, Item& b) {
    return ((double) a.value / a.weight) > ((double) b.value / b.weight);
}

// function to return fractionalweights
double fractionalKnapsack(int W, Item arr[], int n)
{
    sort(arr, arr + n, compare);

    double value = 0;
    for (int i = 0; i < n && W > 0; i++) {
        if (W >= arr[i].weight) {
            value += arr[i].value;
            W -= arr[i].weight;
        } else {
            value += ((double) arr[i].value / arr[i].weight) * W;
            W = 0;
        }
    }

    return value;
}

int main()
{
    int t;
    //taking testcases
    cin >> t;
    cout << setprecision(2) << fixed;
    while (t--)
    {
        //size of array and weight
        int n, W;
        cin >> n >> W;

        Item arr[n];
        //value and weight of each item
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i].value >> arr[i].weight;
        }

        //function call
        cout << fractionalKnapsack(W, arr, n) << endl;
    }
    return 0;
}