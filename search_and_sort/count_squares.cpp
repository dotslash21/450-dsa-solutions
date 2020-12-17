/**
 * @file count_squares.cpp
 * @author Arunangshu Biswas (arunangshubsws@gmail.com)
 * @brief https://practice.geeksforgeeks.org/problems/count-squares3649/1#
 * @version 0.1
 * @date 2020-12-17
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int countSquares(int N) {
        int sqrt_n = sqrt(N);
        int count = 0;
        for (int i = 1; i <= sqrt_n; i++) {
            if (i * i < N)
                count++;
        }
        return count;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;

        Solution ob;
        cout << ob.countSquares(N) << endl;
    }
    return 0;
}