/**
 * @file roman_number_to_integer.cpp
 * @author Arunangshu Biswas (arunangshubsws@gmail.com)
 * @brief https://practice.geeksforgeeks.org/problems/roman-number-to-integer/0
 * @version 0.1
 * @date 2020-12-02
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include <bits/stdc++.h>
using namespace std;

int romanToDecimal(string &);

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        cout << romanToDecimal(s) << endl;
    }
}

int getVal(char c)
{
    switch (c)
    {
    case 'I':
        return 1;

    case 'V':
        return 5;

    case 'X':
        return 10;

    case 'L':
        return 50;

    case 'C':
        return 100;

    case 'D':
        return 500;

    case 'M':
        return 1000;

    default:
        return INT_MIN;
    }
}

// str given roman number string
// Returns decimal value of roman numaral
int romanToDecimal(string &str)
{
    int top = 0;
    int result = 0;
    while (top < str.size())
    {
        int a = getVal(str[top]);
        top++;

        int b = (top < str.size()) ? getVal(str[top]) : 0;

        if (a < b)
        {
            result += (b - a);
            top++;
        }
        else
        {
            result += a;
        }
    }

    return result;
}