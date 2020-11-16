/**
 * @file three_way_partitioning.cpp
 * @author Arunangshu Biswas (arunangshubsws@gmail.com)
 * @brief https://practice.geeksforgeeks.org/problems/three-way-partitioning/1#
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
    void threeWayPartition(vector<int> &array, int a, int b)
    {
        if (array.size() <= 1 || a > b)
            return;

        int low = 0, high = array.size() - 1;
        for (int i = 0; i <= high;)
        {
            if (array[i] < a)
                swap(array[i++], array[low++]);
            else if (array[i] > b)
                swap(array[i], array[high--]);
            else
                i++;
        }
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin >> N;

        vector<int> array(N);
        unordered_map<int, int> ump;

        for (int i = 0; i < N; i++)
        {
            cin >> array[i];
            ump[array[i]]++;
        }

        int a, b;
        cin >> a >> b;

        vector<int> original = array;

        int k1 = 0, k2 = 0, k3 = 0;
        int kk1 = 0;
        int kk2 = 0;
        int kk3 = 0;

        for (int i = 0; i < N; i++)
        {
            if (original[i] > b)
                k3++;
            else if (original[i] <= b and original[i] >= a)
                k2++;
            else if (original[i] < b)
                k1++;
        }

        Solution ob;
        ob.threeWayPartition(array, a, b);

        for (int i = 0; i < k1; i++)
        {
            if (array[i] < b)
                kk1++;
        }

        for (int i = k1; i < k1 + k2; i++)
        {
            if (array[i] <= b and array[i] >= a)
                kk2++;
        }

        for (int i = k1 + k2; i < k1 + k2 + k3; i++)
        {
            if (array[i] > b)
                kk3++;
        }
        bool ok = 0;
        if (k1 == kk1 and k2 == kk2 and k3 == kk3)
            ok = 1;

        for (int i = 0; i < array.size(); i++)
            ump[array[i]]--;

        for (int i = 0; i < array.size(); i++)
            if (ump[array[i]] != 0)
                ok = 0;

        if (ok)
            cout << 1 << endl;
        else
            cout << 0 << endl;
    }

    return 0;
}