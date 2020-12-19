/**
 * @file middle_of_three.cpp
 * @author Arunangshu Biswas (arunangshubsws@gmail.com)
 * @brief https://practice.geeksforgeeks.org/problems/middle-of-three2926/1
 * @version 0.1
 * @date 2020-12-19
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include <bits/stdc++.h>
using namespace std;

//User function template for C++
class Solution
{
public:
    int middle(int A, int B, int C)
    {
        if (A > B)
        {
            if (A < C)
            {
                return A;
            }
            else
            {
                if (B > C)
                {
                    return B;
                }
                else
                {
                    return C;
                }
            }
        }
        else if (A > C)
        {
            return A;
        }
        else
        {
            if (B > C)
            {
                return C;
            }
            else
            {
                return B;
            }
        }
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int A, B, C;
        cin >> A >> B >> C;
        Solution ob;
        cout << ob.middle(A, B, C) << "\n";
    }
    return 0;
}