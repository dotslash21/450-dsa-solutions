/**
 * @file n_meetings_in_one_room.cpp
 * @author Arunangshu Biswas (arunangshubsws@gmail.com)
 * @brief https://www.geeksforgeeks.org/find-maximum-meetings-in-one-room/
 * @version 0.1
 * @date 2020-11-06
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include <bits/stdc++.h>
using namespace std;

bool compare(pair<int, pair<int, int>>& a, pair<int, pair<int, int>>& b) {
    return a.second.second < b.second.second;
}

int main() {
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<pair<int, pair<int, int>>> intervals(n);
        for (int i = 0 ; i < n; i++) {
            intervals[i].first = i + 1;
            cin >> intervals[i].second.first;
        }
        for (int i = 0 ; i < n; i++) {
            cin >> intervals[i].second.second;
        }

        sort(intervals.begin(), intervals.end(), compare);

        int prevEnd = INT_MIN;
        for (int i = 0; i < n; i++) {
            if (intervals[i].second.first >= prevEnd) {
                cout << intervals[i].first << " ";
                prevEnd = intervals[i].second.second;
            }
        }
    }

    return 0;
}
