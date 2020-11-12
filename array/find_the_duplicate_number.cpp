/**
 * @file find_the_duplicate_number.cpp
 * @author Arunangshu Biswas (arunangshubsws@gmail.com)
 * @brief https://leetcode.com/problems/find-the-duplicate-number/
 * @version 0.1
 * @date 2020-11-13
 * 
 * @copyright Copyright (c) 2020
 * 
 */

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        // Set the slow pointer
        int slow = nums[nums[0]];
        
        // Set the fast pointer
        int fast = nums[nums[nums[0]]];
        
        // Detect the loop
        while (slow != fast) {
            slow = nums[slow];
            fast = nums[nums[fast]];
        }
        
        // Reset the slow
        slow = nums[0];
        
        // Start iteration again with same speed
        while (slow != fast) {
            slow = nums[slow];
            fast = nums[fast];
        }
        
        return slow;
    }
};