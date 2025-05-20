'''
Source: https://leetcode.com/problems/longest-increasing-subsequence/description/
Date: 19 May 2025
Author: Rastri Dey 

************************************************************************************

Given an integer array nums, return the length of the longest strictly increasing subsequence.

Example 1:

Input: nums = [10,9,2,5,3,7,101,18]
Output: 4
Explanation: The longest increasing subsequence is [2,3,7,101], therefore the length is 4.
Example 2:

Input: nums = [0,1,0,3,2,3]
Output: 4
Example 3:

Input: nums = [7,7,7,7,7,7,7]
Output: 1
 

Constraints:

1 <= nums.length <= 2500
-104 <= nums[i] <= 104

************************************************************************************

# Approach: Top Down
# Time: O(N^2) Double iteration
# Space: O(N) Recursive Call Stack

'''

from functools import cache

class Solution:
    def lengthOfLIS(self, nums: List[int]) -> int:
        # For every index i, check for all the subsequences at each j
        # before i, that how adding nums[i] impacts the strictly 
        # increasing subsequence length to the index j

        @cache
        def dp(i):
            # Base case: Each element is a subsequence in itself
            maxLen = 1

            for j in range(0,i):
                if (nums[i]>nums[j]):
                    maxLen = max(maxLen, dp(j)+1)

            return maxLen
        
        return max(dp(i) for i in range(len(nums)))