/*
Source: https://leetcode.com/problems/house-robber/description/
Date: 09 June 2024
Author: Rastri Dey 
*/
/************************************************************************************
You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security systems connected and it will automatically contact the police if two adjacent houses were broken into on the same night.

Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police.

Example 1:

Input: nums = [1,2,3,1]
Output: 4
Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
Total amount you can rob = 1 + 3 = 4.
Example 2:

Input: nums = [2,7,9,3,1]
Output: 12
Explanation: Rob house 1 (money = 2), rob house 3 (money = 9) and rob house 5 (money = 1).
Total amount you can rob = 2 + 9 + 1 = 12.

Constraints:

1 <= nums.length <= 100
0 <= nums[i] <= 400
*************************************************************************************/

// Approach: Optimized Dynamic Programming (Iterative Bottom Up)
// Time: O(n)
// Space: O(1)
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        // At the last house, there is nothing to rob
        int dp_next2 = 0;
        // At the 2nd last house, only the last house can be robbed
        int dp_next = nums[n-1];
        // Rob max of either the current(i) & (i+2) house, as no 2 adjacent house can be robbed
        // Or rob just max until the next house 
        for(int i=n-2; i>=0; i--){
            int curr = max(nums[i]+dp_next2, dp_next);
            dp_next2 = dp_next;
            dp_next = curr;
        }
        return dp_next;
    }
};