/*
Source: https://leetcode.com/problems/max-area-of-island/
Date: 23 Oct 2023
Author: Rastri Dey 
*/
/******************************************************************************************
You are given an m x n binary matrix grid. An island is a group of 1's (representing land) connected 4-directionally (horizontal or vertical.) You may assume all four edges of the grid are surrounded by water.

The area of an island is the number of cells with a value 1 in the island.

Return the maximum area of an island in grid. If there is no island, return 0.

Example 1:

Input: grid = [[0,0,1,0,0,0,0,1,0,0,0,0,0],[0,0,0,0,0,0,0,1,1,1,0,0,0],[0,1,1,0,1,0,0,0,0,0,0,0,0],[0,1,0,0,1,1,0,0,1,0,1,0,0],[0,1,0,0,1,1,0,0,1,1,1,0,0],[0,0,0,0,0,0,0,0,0,0,1,0,0],[0,0,0,0,0,0,0,1,1,1,0,0,0],[0,0,0,0,0,0,0,1,1,0,0,0,0]]
Output: 6
Explanation: The answer is not 11, because the island must be connected 4-directionally.
Example 2:

Input: grid = [[0,0,0,0,0,0,0,0]]
Output: 0

Constraints:

m == grid.length
n == grid[i].length
1 <= m, n <= 50
grid[i][j] is either 0 or 1.
*******************************************************************************************/

// Approach: Depth First Search
// Time: O(R*C) (R,C) = no.of row,col of grid
// Space: O(R*C) Recursion call for all squares & seen matrix
class Solution {
public:
    vector<vector<int>> dir{{-1,0},{0,-1},{1,0},{0,1}};
    int m, n;
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        int ans = 0; int ar;
        for(int i=0; i<m; i++){
          for(int j=0; j<n; j++){
            if(grid[i][j]){
              grid[i][j]=0;
              ans = max(ans, dfs(i,j,grid)+1);
            }
          }
        }
      return ans;
    }

    int dfs(int r, int c, vector<vector<int>> &grid){
      int ans = 0;
      for(vector<int> v:dir){
        int nr=r+v[0]; int nc=c+v[1];
        if(valid(nr,nc) && grid[nr][nc]){
          grid[nr][nc]=0;
          ans++;
          ans+=dfs(nr,nc, grid); 
        }
      }
      return ans;
    }
    bool valid(int r, int c){
      return (r>=0 && r<m && c>=0 && c<n);
    }
};