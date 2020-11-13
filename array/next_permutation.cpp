/**
 * @file next_permutation.cpp
 * @author Arunangshu Biswas (arunangshubsws@gmail.com)
 * @brief https://leetcode.com/problems/next-permutation/
 * @version 0.1
 * @date 2020-11-13
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    static int getNextGreaterIndex(int i, vector<int> &nums) {
        int lo = i + 1;
        int hi = nums.size() - 1;

        int nextGreater = lo;
        while (lo <= hi) {
            int mid = ceil((double)(lo + hi) / 2.0);

            if (nums[mid] > nums[i]) {
                lo = mid + 1;

                if (nums[mid] <= nums[nextGreater])
                    nextGreater = mid;
            } else if (nums[mid] <= nums[i]) {
                hi = mid - 1;
            }
        }

        return nextGreater;
    }

    void nextPermutation(vector<int> &nums)
    {
        int n = nums.size();

        if (n <= 1)
            return;

        // Find the element where decending ordering breaks form right.
        int i = n - 2;
        while (i > -1 && (nums[i] >= nums[i + 1]))
            i--;

        // Check if permutation is the last one
        if (i == -1) {
            // Reset to begining of permutation
            reverse(nums.begin(), nums.end());
            return;
        }

        // Find the next greatest element in [i+1, n)
        int nextGreater = getNextGreaterIndex(i, nums);

        // Swap the next greater element with ith position
        iter_swap(nums.begin() + i, nums.begin() + nextGreater);

        // Reverse [i, n)
        reverse(nums.begin() + i + 1, nums.end());
    }
};

int main() {
    vector<int> nums{2,3,1,3,3};
    Solution solution;
    solution.nextPermutation(nums);

    for (int i = 0; i < nums.size(); i++) {
        cout << nums[i] << " ";
    }
    cout << endl;

    return 0;
}