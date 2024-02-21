/*
Source: https://leetcode.com/problems/word-search/
Date: 21 Feb 2024
Author: Rastri Dey 
*/
/*********************************************************************************
 Given an m x n grid of characters board and a string word, return true if word exists in the grid.

The word can be constructed from letters of sequentially adjacent cells, where adjacent cells are horizontally or vertically neighboring. The same letter cell may not be used more than once.
Example 1:

Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCCED"
Output: true
Example 2:

Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "SEE"
Output: true
Example 3:

Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCB"
Output: false
 
Constraints:

m == board.length
n = board[i].length
1 <= m, n <= 6
1 <= word.length <= 15
board and word consists of only lowercase and uppercase English letters.
**********************************************************************************/

// Approach: Backtracking
// Time: O(N*3^L)
// Space: O(L)

class Solution {
public:
    vector<vector<bool>> seen;
    vector<vector<int>> dirs{{0,1},{1,0},{0,-1},{-1,0}};
    string target;
    int m; int n;
    bool exist(vector<vector<char>>& board, string word) {
        m = board.size();
        n = board[0].size();
        seen = vector(m,vector<bool>(n,false));
        target = word;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(board[i][j]==word[0]){
                    seen[i][j] = true;
                    if(backtrack(i,j,1,board)){
                        return true;
                    }  
                    seen[i][j] = false;
                }
            }
        }
        return false;
    }
    bool backtrack(int r, int c, int id, vector<vector<char>>& board){
        if(id==target.size()){
            return true;
        }
        for(vector<int>& d:dirs){
            int nr = r+d[0];
            int nc = c+d[1];
            // Do not go through the visited cells
            if(valid(nr,nc) && !seen[nr][nc] && board[nr][nc]==target[id]){
                seen[nr][nc]=true;
                if(backtrack(nr, nc, id+1, board)){
                    return true;
                }
                seen[nr][nc]=false;    
            }
        }
        return false;
    }
    // Cell is valid or not
    bool valid(int r, int c){
        return (r>=0 && r<m && c>=0 && c<n);
    }
};