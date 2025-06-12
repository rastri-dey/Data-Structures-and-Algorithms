'''
Source: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/description/
Date: 09 Jun 2025
Author: Rastri Dey 

************************************************************************************

You are given an array prices where prices[i] is the price of a given stock on the ith day, and an integer fee representing a transaction fee.

Find the maximum profit you can achieve. You may complete as many transactions as you like, but you need to pay the transaction fee for each transaction.

Note:

You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).
The transaction fee is only charged once for each stock purchase and sale.
 

Example 1:

Input: prices = [1,3,2,8,4,9], fee = 2
Output: 8
Explanation: The maximum profit can be achieved by:
- Buying at prices[0] = 1
- Selling at prices[3] = 8
- Buying at prices[4] = 4
- Selling at prices[5] = 9
The total profit is ((8 - 1) - 2) + ((9 - 4) - 2) = 8.
Example 2:

Input: prices = [1,3,7,5,10,3], fee = 3
Output: 6
 

Constraints:

1 <= prices.length <= 5 * 104
1 <= prices[i] < 5 * 104
0 <= fee < 5 * 104

************************************************************************************

# Approach: Top Down
# Time: O(N)
# Space: O(N)

'''

from functools import cache

class Solution:
    def maxProfit(self, prices: List[int], fee: int) -> int:
        # At every i: what to do (either skip or based on hold sell/buy)
        # Output is max profit
        N = len(prices)
        @cache
        def dp(i: int, hold: int) -> int:
            if (i>=N):
                return 0
            
            if hold==0:
                # Skip or Buy
                return max(dp(i+1, hold), -prices[i]+dp(i+1, 1-hold))
            else:
                # Skip or Sell (with fee)
                return max(dp(i+1, hold), prices[i]-fee+dp(i+1, 1-hold))

        return dp(0,0)   

# Approach: Bottom Up
# Time: O(N)
# Space: O(N)
from functools import cache
class Solution:
    def maxProfit(self, prices: List[int], fee: int) -> int:
        # At every i: what to do (either skip or based on hold sell/buy)
        # Output is max profit
        N = len(prices)
        dp  = [[0]*2 for _ in range(N+1)]

        for i in range(N-1,-1,-1):
            for j in range(2):
                if j == 0:
                    # Skip or Buy
                    dp[i][j] = max(dp[i+1][j], -prices[i]+dp[i+1][1])
                else:
                    # Skip or Sell (with fee)
                    dp[i][j] = max(dp[i+1][j], prices[i]-fee+dp[i+1][0])

        return dp[0][0]      