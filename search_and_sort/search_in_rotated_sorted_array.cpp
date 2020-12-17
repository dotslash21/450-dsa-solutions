/**
 * @file search_in_rotated_sorted_array.cpp
 * @author Arunangshu Biswas (arunangshubsws@gmail.com)
 * @brief https://leetcode.com/problems/search-in-rotated-sorted-array/
 * @version 0.1
 * @date 2020-12-17
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        int lo = 0, hi = nums.size() - 1;

        while (lo <= hi)
        {
            int mid = lo + (hi - lo) / 2;

            if (nums[mid] == target)
            {
                return mid;
            }
            else if (nums[lo] <= nums[mid])
            {
                if (target >= nums[lo] && target <= nums[mid])
                {
                    hi = mid - 1;
                }
                else
                {
                    lo = mid + 1;
                }
            }
            else if (target >= nums[mid] && target <= nums[hi])
            {
                lo = mid + 1;
            }
            else
            {
                hi = mid - 1;
            }
        }

        return -1;
    }
};

int main()
{
    Solution s;
    vector<int> nums{4, 5, 6, 7, 0, 1, 2};
    int target = 0;
    cout << s.search(nums, target) << "\n";
}