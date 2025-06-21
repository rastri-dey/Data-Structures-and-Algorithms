'''
Source: https://leetcode.com/problems/minimum-falling-path-sum/description/
Date: 21 Jun 2025
Author: Rastri Dey 

************************************************************************************

Given an n x n array of integers matrix, return the minimum sum of any falling path through matrix.

A falling path starts at any element in the first row and chooses the element in the next row that is either directly below or diagonally left/right. Specifically, the next element from position (row, col) will be (row + 1, col - 1), (row + 1, col), or (row + 1, col + 1).

Example 1:

Input: matrix = [[2,1,3],[6,5,4],[7,8,9]]
Output: 13
Explanation: There are two falling paths with a minimum sum as shown.
Example 2:

Input: matrix = [[-19,57],[-40,-5]]
Output: -59
Explanation: The falling path with a minimum sum is shown.

Constraints:

n == matrix.length == matrix[i].length
1 <= n <= 100
-100 <= matrix[i][j] <= 100

************************************************************************************
'''
# Approach: Dynamic Programming Matrix with Depth First Search
# Time: O(N^2)
# Space: O(N^2)

from functools import cache

class Solution:
    def minFallingPathSum(self, matrix: List[List[int]]) -> int:

       # Observe that the constraint says:
       # the cell value may hold negative no.s as well. 
       # So don't put minimum just for the next row, consider 
       # the current cell's value within the minimum comparison too

        n = len(matrix)

        @cache
        def dp(row: int, col: int) -> int:

            # As it's minimum, we can't put 0 for the boundary cases, 
            # else it will mistakenly be considered as min because of 0
            # Although if the constraints would have said, all the values are only
            # negative, then 0 would have worked, because negatives' sum would
            # always be lower than 0 and give right output in minimum calculation

            if(col<0 or col>n-1):
                return float('inf')
            
            if(row==n-1):
                return matrix[row][col]

            min_sum = matrix[row][col]
            min_sum = min(min_sum+dp(row+1,col-1),min_sum+dp(row+1,col), min_sum+dp(row+1,col+1))
        
            return min_sum

        min_val = float('inf')

        # Consider each cell in the first row as the root and apply DFS
        for i in range(n):
            min_val = min(min_val, dp(0,i))

        return min_val
        