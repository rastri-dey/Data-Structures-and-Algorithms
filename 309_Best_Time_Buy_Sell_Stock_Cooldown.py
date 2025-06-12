'''
Source: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/description/
Date: 11 Jun 2025
Author: Rastri Dey 

************************************************************************************

You are given an array prices where prices[i] is the price of a given stock on the ith day.

Find the maximum profit you can achieve. You may complete as many transactions as you like (i.e., buy one and sell one share of the stock multiple times) with the following restrictions:

After you sell your stock, you cannot buy stock on the next day (i.e., cooldown one day).
Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).

Example 1:

Input: prices = [1,2,3,0,2]
Output: 3
Explanation: transactions = [buy, sell, cooldown, buy, sell]
Example 2:

Input: prices = [1]
Output: 0
 

Constraints:

1 <= prices.length <= 5000
0 <= prices[i] <= 1000

************************************************************************************

# Approach: Top Down
# Time: O(N)
# Space: O(N)
'''

from functools import cache

class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        N = len(prices)
        @cache
        def dp(i: int, hold: int) -> int:
            if(i >= N):
                return 0

            if(hold==0):
                # Buy or Skip
                return max(-prices[i]+dp(i+1,1), dp(i+1,hold))
            else:
                # Sell & cooldown or Skip
                return max(prices[i]+dp(i+2,0), dp(i+1,hold))

        return dp(0,0)

# Approach: Bottom Up
# Time: O(N)
# Space: O(N)

class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        N = len(prices)
        # Always take the max size of iteration from the inner loop (here N+2)
        dp = [[0]*2 for _ in range(N+2)]

        for i in range(N-1,-1,-1):
            for j in range(2):
                if(j==0):
                    # Buy or Skip
                    dp[i][j] = max(-prices[i]+dp[i+1][1], dp[i+1][j])
                else:
                    # Sell & cooldown or Skip
                    dp[i][j] = max(prices[i]+dp[i+2][0], dp[i+1][j])

        return dp[0][0]
        