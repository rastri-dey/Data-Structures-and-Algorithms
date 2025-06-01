'''
Source: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/description/
Date: 01 Jun 2025
Author: Rastri Dey 

************************************************************************************

You are given an integer array prices where prices[i] is the price of a given stock on the ith day, and an integer k.

Find the maximum profit you can achieve. You may complete at most k transactions: i.e. you may buy at most k times and sell at most k times.

Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).

Example 1:

Input: k = 2, prices = [2,4,1]
Output: 2
Explanation: Buy on day 1 (price = 2) and sell on day 2 (price = 4), profit = 4-2 = 2.
Example 2:

Input: k = 2, prices = [3,2,6,5,0,3]
Output: 7
Explanation: Buy on day 2 (price = 2) and sell on day 3 (price = 6), profit = 6-2 = 4. Then buy on day 5 (price = 0) and sell on day 6 (price = 3), profit = 3-0 = 3.
 

Constraints:

1 <= k <= 100
1 <= prices.length <= 1000
0 <= prices[i] <= 1000

************************************************************************************

# Approach: Top Down Memoization
# Time: O(N*K)
# Space: O(N*K)

'''
from functools import cache

class Solution:
    def maxProfit(self, k: int, prices: List[int]) -> int:
        N = len(prices)
        # Return max profit
        @cache
        def dp(i: int, stock_hold: int, remain: int) -> int:

            # Base case
            if (remain==0 or i>=N):
                return 0

            # Last time NOT bought, currently looking to skip or BUY 
            if (stock_hold == 0):
                return max(dp(i+1, stock_hold, remain), -prices[i]+dp(i+1, 1-stock_hold, remain))

            # Last time bought, currently looking to skip or SELL 
            else:
                return max(dp(i+1, stock_hold, remain), prices[i]+dp(i+1, 1-stock_hold, remain-1))

        return dp(0, 0, k)