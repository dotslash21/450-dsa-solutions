/**
 * @file find_element_appearing_nbyk.cpp
 * @author Arunangshu Biswas (arunangshubsws@gmail.com)
 * @brief https://www.geeksforgeeks.org/given-an-array-of-of-size-n-finds-all-the-elements-that-appear-more-than-nk-times/
 * @version 0.1
 * @date 2020-11-15
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include <bits/stdc++.h>
using namespace std;

struct elementCount
{
    int element;
    int count;
};

// Simmilar to moore's voting algorithm
// Time: O(nk), Space: O(k-1)
void findMoreThanNdK(int arr[], int n, int k)
{
    if (k < 2)
        return;

    struct elementCount counts[k - 1];
    for (int i = 0; i < k - 1; i++)
        counts[i].count = 0;

    // find majority element candidates
    for (int i = 0; i < n; i++)
    {
        int j = 0;

        while (j < k - 1)
        {
            if (counts[j].element == arr[i])
            {
                counts[j].count += 1;
                break;
            }

            j++;
        }

        if (j == k - 1)
        {
            int l = 0;

            while (l < k - 1)
            {
                if (counts[l].count == 0)
                {
                    counts[l].element = arr[i];
                    counts[l].count = 1;
                    break;
                }

                l++;
            }

            if (l == k - 1)
                for (l = 0; l < k - 1; l++)
                    counts[l].count -= 1;
        }
    }

    for (int i = 0; i < k - 1; i++)
    {
        int actualCount = 0;
        for (int j = 0; j < n; j++)
            if (arr[j] == counts[i].element)
                actualCount++;

        if (actualCount > n / k)
            cout << counts[i].element << " ";
    }
    cout << "\n";
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        findMoreThanNdK(arr, n, k);
    }

    return 0;
}