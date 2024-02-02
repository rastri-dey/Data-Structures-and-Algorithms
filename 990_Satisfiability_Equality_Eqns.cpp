/*
Source: https://leetcode.com/problems/satisfiability-of-equality-equations/
Date: 15 Dec 2023
Author: Rastri Dey 
*/
/*************************************************************************************
You are given an array of strings equations that represent relationships between variables where each string equations[i] is of length 4 and takes one of two different forms: "xi==yi" or "xi!=yi".Here, xi and yi are lowercase letters (not necessarily different) that represent one-letter variable names.

Return true if it is possible to assign integers to variable names so as to satisfy all the given equations, or false otherwise.

Example 1:

Input: equations = ["a==b","b!=a"]
Output: false
Explanation: If we assign say, a = 1 and b = 1, then the first equation is satisfied, but not the second.
There is no way to assign the variables to satisfy both equations.
Example 2:

Input: equations = ["b==a","a==b"]
Output: true
Explanation: We could assign a = 1 and b = 1 to satisfy both equations.
 
Constraints:

1 <= equations.length <= 500
equations[i].length == 4
equations[i][0] is a lowercase letter.
equations[i][1] is either '=' or '!'.
equations[i][2] is '='.
equations[i][3] is a lowercase letter.
*********************************************************************************/
// Approach: DFS Graphs
// Time : O(n) where n = equations.size()
// Space : O(max(n,26)) = O(n)
class Solution {
public:
    bool equationsPossible(vector<string>& equations) {
        vector<vector<int>> graph(26);
        int x;
        int y;
        for(string s: equations){
            if(s[1]=='='){
                x = s[0] - 'a';
                y = s[3] - 'a';
                graph[x].push_back(y);
                graph[y].push_back(x);
            }
        }
        vector<bool> seen(26,false);
        for(string s: equations){
            if(s[1]=='!'){
                x = s[0] - 'a';
                y = s[3] - 'a';
                if(x==y) return false;
                if(!dfs(x, y, seen, graph))
                    return false;
            }
        }
        return true;
    }
    bool dfs(int src, int dest, vector<bool> seen,vector<vector<int>> graph){
        bool ans = true;
        for(auto c: graph[src]){
            if(!seen[c]){
                seen[c] = true;
                if(c==dest) return false;
                ans &= dfs(c, dest, seen, graph);
            }         
        }
        return ans;
    }
};