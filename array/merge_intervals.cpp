/**
 * @file merge_intervals.cpp
 * @author Arunangshu Biswas (arunangshubsws@gmail.com)
 * @brief https://leetcode.com/problems/merge-intervals/
 * @version 0.1
 * @date 2020-11-13
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    static bool compareIntervals(const vector<int>& a, const vector<int>& b) {
        return a[0] < b[0];
    }
    
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), compareIntervals);
        
        vector<vector<int>> result;
        for (auto interval : intervals) {
            if (!result.empty() && result.back()[1] >= interval[0]) {
                result.back()[1] = max(result.back()[1], interval[1]);
            } else {
                result.push_back(interval);
            }
        }
        
        return result;
    }
};

int main() {
    Solution solution;
    vector<vector<int>> intervals{{1,3},{2,6},{8,10},{15,18}};
    vector<vector<int>> result = solution.merge(intervals);

    for (vector<int> interval : result) {
        cout << interval[0] << " " << interval[1] << "\n";
    }
}