/*
Source: https://leetcode.com/problems/combination-sum-iii/description/
Date: 10 Feb 2024
Author: Rastri Dey 
*/
/**********************************************************************
Find all valid combinations of k numbers that sum up to n such that the following conditions are true:

Only numbers 1 through 9 are used.
Each number is used at most once.
Return a list of all possible valid combinations. The list must not contain the same combination twice, and the combinations may be returned in any order.

Example 1:

Input: k = 3, n = 7
Output: [[1,2,4]]
Explanation:
1 + 2 + 4 = 7
There are no other valid combinations.
Example 2:

Input: k = 3, n = 9
Output: [[1,2,6],[1,3,5],[2,3,4]]
Explanation:
1 + 2 + 6 = 9
1 + 3 + 5 = 9
2 + 3 + 4 = 9
There are no other valid combinations.
Example 3:

Input: k = 4, n = 1
Output: []
Explanation: There are no valid combinations.
Using 4 different numbers in the range [1,9], the smallest sum we can get is 1+2+3+4 = 10 and since 10 > 1, there are no valid combination. 

Constraints:

2 <= k <= 9
1 <= n <= 60
********************************************************************************/

// Approach: Backtracking

// Time: O(P(9,K)*K) Calculate no. of nodes => If K numbers are allowed, 
// then at first 9 values are possible, then for
// 2nd 8 values are possible. Likewise for K places, P(9,K) is allowed
// E.g., K=3: 7*8*9 => 9!/(9-K)! => P(9,K)

// Space: O(K) Recursive stack of K depth, curr.size()=K

class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> curr;
        backtrack(1, 0, k, n, curr, ans);  
      return ans;
    }
    void backtrack(int id, int sum, int k, int n, vector<int>&curr, vector<vector<int>>&ans){
      if(curr.size()==k){
        if(sum==n){
        // In the last step, we make a copy of curr into ans,
        // making time complexity as k
          ans.push_back(curr);
        }
         return; 
      }
      for(int i=id; i<10; i++){
        if(sum+i<=n){
          curr.push_back(i);
          // id = i+1 start from next value
          backtrack(i+1,sum+i, k, n, curr, ans);
          curr.pop_back();
        }
      }
      return;
    }
};