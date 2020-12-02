/**
 * @file min_number_of_flips.cpp
 * @author Arunangshu Biswas (arunangshubsws@gmail.com)
 * @brief https://practice.geeksforgeeks.org/problems/min-number-of-flips/0#
 * @version 0.1
 * @date 2020-12-02
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include <bits/stdc++.h>
using namespace std;

char flip(char ch)
{
    return ch == '0' ? '1' : '0';
}

int minFlips(string binary)
{
    int flipsWithZeroStart = 0;
    int flipsWithOneStart = 0;

    char expectedZeroStart = '0';
    char expectedOneStart = '1';

    for (int i = 0; i < binary.size(); i++)
    {
        if (binary[i] != expectedZeroStart)
        {
            flipsWithZeroStart++;
        }

        if (binary[i] != expectedOneStart)
        {
            flipsWithOneStart++;
        }

        expectedZeroStart = flip(expectedZeroStart);
        expectedOneStart = flip(expectedOneStart);
    }

    return min(flipsWithZeroStart, flipsWithOneStart);
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string binary;
        cin >> binary;
        cout << minFlips(binary) << "\n";
    }
    return 0;
}