'''
Source: https://leetcode.com/problems/minimum-path-sum/description/
Date: 15 Jun 2025
Author: Rastri Dey 

************************************************************************************

Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right, which minimizes the sum of all numbers along its path.

Note: You can only move either down or right at any point in time.

Example 1:


Input: grid = [[1,3,1],[1,5,1],[4,2,1]]
Output: 7
Explanation: Because the path 1 → 3 → 1 → 1 → 1 minimizes the sum.
Example 2:

Input: grid = [[1,2,3],[4,5,6]]
Output: 12
 

Constraints:

m == grid.length
n == grid[i].length
1 <= m, n <= 200
0 <= grid[i][j] <= 200

************************************************************************************

# Approach: Dynamic Programming Matrix (Top Down)
# Time: O(N*M)
# Space: O(N*M)
'''
from functools import cache
class Solution:
    def minPathSum(self, grid: List[List[int]]) -> int:
        m = len(grid)
        n = len(grid[0])
        @cache
        def dp(row: int, col: int) -> int:
            if row == 0 and col == 0:
                return grid[row][col]

            if row>0 and col>0:
                return grid[row][col]+min(dp(row-1, col), dp(row, col-1))
            
            # At the first col, we can only move from row above
            if (col==0):
                return grid[row][col] + dp(row-1, col)

            # At the first row, we can only move from col behind
            if (row==0):
                return grid[row][col] + dp(row, col-1)
            
        return dp(m-1,n-1)        