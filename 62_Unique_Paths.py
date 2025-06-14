'''
Source: https://leetcode.com/problems/unique-paths/description/
Date: 15 Jun 2025
Author: Rastri Dey 

************************************************************************************

There is a robot on an m x n grid. The robot is initially located at the top-left corner (i.e., grid[0][0]). The robot tries to move to the bottom-right corner (i.e., grid[m - 1][n - 1]). The robot can only move either down or right at any point in time.

Given the two integers m and n, return the number of possible unique paths that the robot can take to reach the bottom-right corner.

The test cases are generated so that the answer will be less than or equal to 2 * 109.

Example 1:

Input: m = 3, n = 7
Output: 28
Example 2:

Input: m = 3, n = 2
Output: 3
Explanation: From the top-left corner, there are a total of 3 ways to reach the bottom-right corner:
1. Right -> Down -> Down
2. Down -> Down -> Right
3. Down -> Right -> Down
 

Constraints:

1 <= m, n <= 100

************************************************************************************

# Approach: Recursive memoization (Don't think it should be called as a DP problem)
# Time: O(M*N)
# Space: O(M*N)

'''

from functools import cache
class Solution:
    def uniquePaths(self, m: int, n: int) -> int:
        @cache
        def memo(row: int, col: int) -> int:
            if row == 0 and col == 0:
                return 1

            ways = 0

            if row>0:
                ways += memo(row-1, col)

            if col>0:
                ways += memo(row, col-1)

            return ways

        return memo(m-1,n-1)
    
# Approach: Bottom Up Iterative (Shouldn't be called as DP)
# Time: O(M*N)
# Space: O(M*N)

class Solution:
    def uniquePaths(self, m: int, n: int) -> int:
        memo = [[0]*n for _ in range(m)]
        memo[0][0] = 1
        for i in range(m):
            for j in range(n):
                if i>0:
                    memo[i][j]+=memo[i-1][j]
                if j>0:
                    memo[i][j]+=memo[i][j-1]

        return memo[m-1][n-1]