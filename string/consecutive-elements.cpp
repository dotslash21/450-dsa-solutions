/**
 * @file consecutive-elements.cpp
 * @author Arunangshu Biswas (arunangshubsws@gmail.com)
 * @brief https://practice.geeksforgeeks.org/problems/consecutive-elements/0
 * @version 0.1
 * @date 2020-12-13
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include <bits/stdc++.h>
using namespace std;

void delConsecutiveElements(string s) {
    char prev = '#';
    for (char c : s) {
        if (c != prev)
            cout << c;
        prev = c;
    }
    cout << "\n";
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        delConsecutiveElements(s);
    }
    
    return 0;
}