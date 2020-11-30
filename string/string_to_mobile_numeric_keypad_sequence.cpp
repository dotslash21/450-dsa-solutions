/**
 * @file string_to_mobile_numeric_keypad_sequence.cpp
 * @author Arunangshu Biswas (arunangshubsws@gmail.com)
 * @brief https://www.geeksforgeeks.org/convert-sentence-equivalent-mobile-numeric-keypad-sequence/
 * @version 0.1
 * @date 2020-11-30
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include <bits/stdc++.h>
using namespace std;

void printEquivalentMobileNumSequence(string &s)
{
    vector<pair<char, int>> numMap = {
        {'2', 1},
        {'2', 2},
        {'2', 3},
        {'3', 1},
        {'3', 2},
        {'3', 3},
        {'4', 1},
        {'4', 2},
        {'4', 3},
        {'5', 1},
        {'5', 2},
        {'5', 3},
        {'6', 1},
        {'6', 2},
        {'6', 3},
        {'7', 1},
        {'7', 2},
        {'7', 3},
        {'7', 4},
        {'8', 1},
        {'8', 2},
        {'8', 3},
        {'9', 1},
        {'9', 2},
        {'9', 3},
        {'9', 4},
    };

    string result = "";
    for (char c : s)
    {
        if (c == ' ')
        {
            result.push_back('0');
            continue;
        }

        char num = numMap[c - 'A'].first;
        int times = numMap[c - 'A'].second;

        for (int i = 0; i < times; i++)
        {
            result.push_back(num);
        }
    }

    cout << result << "\n";
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin.ignore();
        getline(cin, s);

        printEquivalentMobileNumSequence(s);
    }

    return 0;
}