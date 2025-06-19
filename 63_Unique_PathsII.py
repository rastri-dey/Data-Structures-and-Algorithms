'''
Source: https://leetcode.com/problems/unique-paths-ii/description/
Date: 16 Jun 2025
Author: Rastri Dey 

************************************************************************************

You are given an m x n integer array grid. There is a robot initially located at the top-left corner (i.e., grid[0][0]). The robot tries to move to the bottom-right corner (i.e., grid[m - 1][n - 1]). The robot can only move either down or right at any point in time.

An obstacle and space are marked as 1 or 0 respectively in grid. A path that the robot takes cannot include any square that is an obstacle.

Return the number of possible unique paths that the robot can take to reach the bottom-right corner.

The testcases are generated so that the answer will be less than or equal to 2 * 109.

Example 1:

Input: obstacleGrid = [[0,0,0],[0,1,0],[0,0,0]]
Output: 2
Explanation: There is one obstacle in the middle of the 3x3 grid above.
There are two ways to reach the bottom-right corner:
1. Right -> Right -> Down -> Down
2. Down -> Down -> Right -> Right
Example 2:


Input: obstacleGrid = [[0,1],[0,0]]
Output: 1
 
Constraints:

m == obstacleGrid.length
n == obstacleGrid[i].length
1 <= m, n <= 100
obstacleGrid[i][j] is 0 or 1

************************************************************************************
'''
# Approach: Recursive Memoization 
# Time: O(M*N)
# Space: O(M*N)

from functools import cache

class Solution:
    def uniquePathsWithObstacles(self, obstacleGrid: List[List[int]]) -> int:
        m = len(obstacleGrid)
        n = len(obstacleGrid[0])
        @cache
        def memo(row: int, col: int) -> int:
            # Base case
            if (row == 0 and col == 0 and obstacleGrid[row][col]==0):
                return 1
            
            if (obstacleGrid[row][col]==1):
                return 0
            
            if(row>0 and col>0):
                return memo(row,col-1) + memo(row-1,col)

            if (row==0):
                return memo(row,col-1)
            
            if (col==0):
                return memo(row-1,col)
        
        return memo(m-1,n-1)

# Approach: Tabulation
# Time: O(M*N)
# Space: O(M*N)

class Solution:
    def uniquePathsWithObstacles(self, obstacleGrid: List[List[int]]) -> int:
        m = len(obstacleGrid)
        n = len(obstacleGrid[0])
        memo = [[0]*n for _ in range(m)]

        for row in range(m):
            for col in range(n):
                if (row == 0 and col == 0 and obstacleGrid[row][col]==0):
                    memo[row][col] = 1
                    continue

                if (obstacleGrid[row][col]==1):
                    continue
            
                if(row>0 and col>0):
                    memo[row][col] = memo[row][col-1] + memo[row-1][col]

                if (row==0):
                    memo[row][col] = memo[row][col-1]
            
                if (col==0):
                    memo[row][col] = memo[row-1][col]
                    
        return memo[m-1][n-1]  

# Approach: Iterative Tabulation (Linear Space)
# Time: O(M*N)
# Space: O(N) - Linear

class Solution:
    def uniquePathsWithObstacles(self, obstacleGrid: List[List[int]]) -> int:
        m = len(obstacleGrid)
        n = len(obstacleGrid[0])
        memo = [0 for _ in range(n)]

        if obstacleGrid[0][0]==1 or obstacleGrid[m-1][n-1]==1:
            return 0
        
        memo[0] = 1

        for row in range(m):
            last_memo = memo                        
            for col in range(n):

                if(row==0 and col==0):
                    continue

                if (obstacleGrid[row][col]==1):
                    # The trick is that last_memo is assigned to memo without knowing the obstacle
                    # position, so reset it's value here, else the last row's value will get 
                    # mistakely assigned to current memo
                    memo[col] = 0
                    continue
            
                if(row>0 and col>0):
                    memo[col] = memo[col-1] + last_memo[col]

                if (row==0): 
                    memo[col] = memo[col-1]
            
                if (col==0):
                    memo[col] = last_memo[col]
      
        return memo[n-1]              