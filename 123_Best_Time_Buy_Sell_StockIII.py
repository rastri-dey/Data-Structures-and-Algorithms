'''
Source: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/description/
Date: 14 Jun 2025
Author: Rastri Dey 

************************************************************************************

You are given an array prices where prices[i] is the price of a given stock on the ith day.

Find the maximum profit you can achieve. You may complete at most two transactions.

Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).

Example 1:

Input: prices = [3,3,5,0,0,3,1,4]
Output: 6
Explanation: Buy on day 4 (price = 0) and sell on day 6 (price = 3), profit = 3-0 = 3.
Then buy on day 7 (price = 1) and sell on day 8 (price = 4), profit = 4-1 = 3.
Example 2:

Input: prices = [1,2,3,4,5]
Output: 4
Explanation: Buy on day 1 (price = 1) and sell on day 5 (price = 5), profit = 5-1 = 4.
Note that you cannot buy on day 1, buy on day 2 and sell them later, as you are engaging multiple transactions at the same time. You must sell before buying again.
Example 3:

Input: prices = [7,6,4,3,1]
Output: 0
Explanation: In this case, no transaction is done, i.e. max profit = 0.
 

Constraints:

1 <= prices.length <= 10^5
0 <= prices[i] <= 10^5

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
        def dp(i: int, hold: int, k: int) -> int:
            if(i>=N or k<=0):
                return 0

            # Buy or skip
            if(hold==0):
                return max(-prices[i]+dp(i+1,1-hold,k), dp(i+1,hold,k))
            # Sell or skip, complete the transaction
            else:
                return max(prices[i]+dp(i+1,1-hold,k-1), dp(i+1,hold, k))
        
        return dp(0,0,2)
    
# Approach: Bottom Up
# Time: O(N)
# Space: O(N)

class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        N = len(prices)
        dp = [[[0]*(3) for _ in range(2)] for _ in range(N+1)]

        for i in range(N-1,-1,-1):    
            for hold in range(2):
                for k in range(1,3):
                    if hold==0:
                        dp[i][hold][k] = max(-prices[i]+dp[i+1][1][k], dp[i+1][0][k])
                    else:
                        dp[i][hold][k] = max(prices[i]+dp[i+1][0][k-1], dp[i+1][1][k])

        return dp[0][0][2]
        