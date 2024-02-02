/*
Source: https://leetcode.com/problems/rotting-oranges/
Date: 15 Dec 2023
Author: Rastri Dey 
*/
/***********************************************************************************
You are given an m x n grid where each cell can have one of three values:

0 representing an empty cell,
1 representing a fresh orange, or
2 representing a rotten orange.
Every minute, any fresh orange that is 4-directionally adjacent to a rotten orange becomes rotten.

Return the minimum number of minutes that must elapse until no cell has a fresh orange. If this is impossible, return -1.

Example 1:
Input: grid = [[2,1,1],[1,1,0],[0,1,1]]
Output: 4

Example 2:
Input: grid = [[2,1,1],[0,1,1],[1,0,1]]
Output: -1
Explanation: The orange in the bottom left corner (row 2, column 0) is never rotten, because rotting only happens 4-directionally.

Example 3:
Input: grid = [[0,2]]
Output: 0
Explanation: Since there are already no fresh oranges at minute 0, the answer is just 0.
 
Constraints:

m == grid.length
n == grid[i].length
1 <= m, n <= 10
grid[i][j] is 0, 1, or 2.
***********************************************************************************/
// Approach: BFS
// Time : O(n*m) where n*m = grid size
// Space : O(n*m)
class Solution {
public:
    int row;
    int col;
    int orangesRotting(vector<vector<int>>& grid) {
        int numFresh = 0;
        row = grid.size();
        col = grid[0].size();
        queue<vector<int>> q;
        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                if(grid[i][j]==2){
                    q.push({i,j,0});
                }else if(grid[i][j]==1){
                    numFresh++;
                }
            }
        }
        if(numFresh==0) return 0;
        vector<vector<bool>> seen(row, vector(col, false));
        vector<vector<int>> dirs{{0,1},{1,0},{0,-1},{-1,0}};
        while(!q.empty()){
            vector<int> v = q.front();
            q.pop();
            for(auto d: dirs){
                int nr = v[0]+d[0], nc = v[1]+d[1];
                if(valid(nr,nc) && !seen[nr][nc] && grid[nr][nc]==1){
                    numFresh--;
                    seen[nr][nc]=true;
                    q.push({nr,nc, v[2]+1});
                    if(numFresh==0) return v[2]+1;
                }
            }
        } 
        return -1;
    }
    bool valid(int r, int c){
        return (r>=0 && r<row && c>=0 && c<col);
    }
};