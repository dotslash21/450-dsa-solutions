/**
 * @file parenthesis_checker.cpp
 * @author Arunangshu Biswas (arunangshubsws@gmail.com)
 * @brief https://practice.geeksforgeeks.org/problems/parenthesis-checker2744/1
 * @version 0.1
 * @date 2020-11-24
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include <bits/stdc++.h>
using namespace std;

bool isSameBracketType(char opening, char closing)
{
    switch (opening)
    {
    case '{':
        return closing == '}';
        break;

    case '[':
        return closing == ']';
        break;

    case '(':
        return closing == ')';
        break;

    default:
        return false;
    }
}

// Function to return if the paranthesis are balanced or not
bool ispar(string x)
{
    stack<char> st;

    for (char c : x)
    {
        switch (c)
        {
        case '{':
        case '[':
        case '(':
            st.push(c);
            break;

        case '}':
        case ']':
        case ')':
            if (st.empty() || !isSameBracketType(st.top(), c))
                return false;
            else
                st.pop();
            break;

        default:
            throw invalid_argument("Invalid character!");
        }
    }

    if (!st.empty())
        return false;

    return true;
}

int main()
{
    int t;
    string a;
    cin >> t;
    while (t--)
    {
        cin >> a;
        if (ispar(a))
            cout << "balanced" << endl;
        else
            cout << "not balanced" << endl;
    }
}