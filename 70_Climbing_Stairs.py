'''
Source: https://leetcode.com/problems/climbing-stairs/editorial/
Date: 22 May 2025
Author: Rastri Dey 

************************************************************************************

You are climbing a staircase. It takes n steps to reach the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

Example 1:

Input: n = 2
Output: 2
Explanation: There are two ways to climb to the top.
1. 1 step + 1 step
2. 2 steps
Example 2:

Input: n = 3
Output: 3
Explanation: There are three ways to climb to the top.
1. 1 step + 1 step + 1 step
2. 1 step + 2 steps
3. 2 steps + 1 step
 

Constraints:

1 <= n <= 45

************************************************************************************

# Approach: Recursive Memoization
# Time: O(N)
# Space: O(N) Recursive Stack space is used, not good when n is too high

'''
class Solution:
    def climbStairs(self, n: int) -> int:
        @cache
        def dp(i):
            if (i>n):
                return 0
            if (i==n):
                return 1
            return dp(i+1)+dp(i+2)
        return dp(0)

            
        
