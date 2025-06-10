'''
Source: https://leetcode.com/problems/maximum-value-of-k-coins-from-piles/description/
Date: 05 Jun 2025
Author: Rastri Dey 

************************************************************************************
There are n piles of coins on a table. Each pile consists of a positive number of coins of assorted denominations.

In one move, you can choose any coin on top of any pile, remove it, and add it to your wallet.

Given a list piles, where piles[i] is a list of integers denoting the composition of the ith pile from top to bottom, and a positive integer k, return the maximum total value of coins you can have in your wallet if you choose exactly k coins optimally. 

Example 1:

Input: piles = [[1,100,3],[7,8,9]], k = 2
Output: 101
Explanation:
The above diagram shows the different ways we can choose k coins.
The maximum total we can obtain is 101.
Example 2:

Input: piles = [[100],[100],[100],[100],[100],[100],[1,1,1,1,1,1,700]], k = 7
Output: 706
Explanation:
The maximum total can be obtained if we choose all coins from the last pile.
 

Constraints:

n == piles.length
1 <= n <= 1000
1 <= piles[i][j] <= 105
1 <= k <= sum(piles[i].length) <= 2000

************************************************************************************
'''
# Approach: Top Down

from functools import cache
class Solution:
    def maxValueOfCoins(self, piles: List[List[int]], k: int) -> int:
        N = len(piles)
        @cache
        def dp(o: int,remain: int) -> int:
            if o == N or remain == 0:
                return 0
            
            j = min(len(piles[o]),remain)
            ans = dp(o+1, remain)
            curr = 0
            # Skip it or take upto i-th coin in the leftmost pile 
            for i in range(j):
                curr += piles[o][i]
                ans = max(ans, curr+dp(o+1, remain-i-1))
            return ans
        return dp(0,k)
    
 # Approach: Bottom Up  
      
class Solution:
    def maxValueOfCoins(self, piles: List[List[int]], k: int) -> int:
        N = len(piles)
        dp = [[0]*(k+1) for _ in range(N+1)]

        for o in range(N-1,-1,-1):
            for remain in range(1,k+1):
                j = min(len(piles[o]),remain)
                dp[o][remain] = dp[o+1][remain]
                curr = 0
                for i in range(j):
                    curr += piles[o][i]
                    dp[o][remain] = max(dp[o][remain], curr + dp[o + 1][remain - i - 1])

        return dp[0][k]