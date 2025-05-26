'''
Source: https://leetcode.com/problems/coin-change/description/
Date: 26 May 2025
Author: Rastri Dey 

************************************************************************************

You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.

Return the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.

You may assume that you have an infinite number of each kind of coin.

Example 1:

Input: coins = [1,2,5], amount = 11
Output: 3
Explanation: 11 = 5 + 5 + 1
Example 2:

Input: coins = [2], amount = 3
Output: -1
Example 3:

Input: coins = [1], amount = 0
Output: 0
 

Constraints:

1 <= coins.length <= 12
1 <= coins[i] <= 231 - 1
0 <= amount <= 104

************************************************************************************

# Approach: Dynamic Programming Top Down with Depth-First Search recursive tree
# Time: O(S*N) : S (amount) is for depth of the tree, N (size of coins List) is for breadth of the tree  
# Space: O(S) : Recursive tree

'''

class Solution:
    def coinChange(self, coins: List[int], amount: int) -> int:
        @cache
        def dfs(rem: int) -> int:
            if (rem == 0):
                return 0
            if (rem < 0):
                return -1
            min_cost = float('inf')

            # Cost calculation is done along depth for each branch until amount gets 0
            # Gets into the depth of one branch until the rem becomes 0
            # Starts calculating the count for coins from bottom when it is at a leaf node
            # After reaching the leaf node, rem becomes 0, and res becomes positive

            # Minimum cost calculation is done along breadth
            # At a particular node once all the breadth wise calculations are done - 
            # one for loop iteration is done and the minimum cost along breadth is returned to the dfs node prior to that
            # So, as it goes up to the top, minimum cost is allocated  for each node

            for coin in coins:
                res = dfs(rem-coin)
                if res != -1:
                    min_cost = min(min_cost, res+1)
            
            return min_cost if min_cost != float('inf') else -1

        return dfs(amount)      