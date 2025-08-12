'''
Source: https://leetcode.com/problems/minimum-size-subarray-sum/description/
Date: 12 Aug 2025
Author: Rastri Dey 

************************************************************************************

Given an array of positive integers nums and a positive integer target, return the minimal length of a subarray whose sum is greater than or equal to target. If there is no such subarray, return 0 instead.

Example 1:

Input: target = 7, nums = [2,3,1,2,4,3]
Output: 2
Explanation: The subarray [4,3] has the minimal length under the problem constraint.
Example 2:

Input: target = 4, nums = [1,4,4]
Output: 1
Example 3:

Input: target = 11, nums = [1,1,1,1,1,1,1,1]
Output: 0
 
Constraints:

1 <= target <= 109
1 <= nums.length <= 105
1 <= nums[i] <= 104
************************************************************************************
'''
# Approach: Sliding Window
# Time: O(N)
# Space: O(1)

class Solution:
    def minSubArrayLen(self, target: int, nums: List[int]) -> int:
        j = 0
        tsum = 0
        n = len(nums)
        ans = float('Inf')

        for i in range(0,n):
            tsum += nums[i]
            while(tsum >= target and j<=i):
                ans = min(ans, i-j+1)
                tsum -= nums[j] 
                j+=1
            

        return ans if ans!=float('inf') else 0