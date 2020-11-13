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
    static bool compare(vector<int>& a, vector<int>& b) {        
        return a[0] < b[0];
    }

    static bool isOverlapping(vector<int>& a, vector<int>& b) {
        if (b[0] < a[0])
            return isOverlapping(b, a);
        
        return b[0] >= a[0] && b[0] <= a[1];
    }

    static vector<int> mergeIntervals(vector<int>& a, vector<int>& b) {
        return {min(a[0], b[0]), max(a[1], b[1])};
    }

    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.size() <= 1) {
            return intervals;
        }
        
        sort(intervals.begin(), intervals.end(), compare);

        vector<vector<int>> mergedIntervals;
        mergedIntervals.push_back(intervals[0]);
        int last = 0;

        for (int i = 1; i < intervals.size(); i++) {
            if (isOverlapping(intervals[i], mergedIntervals[last])) {
                mergedIntervals[last] = mergeIntervals(intervals[i], mergedIntervals[last]);
            } else {
                mergedIntervals.push_back(intervals[i]);
                last++;
            }
        }

        return mergedIntervals;
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