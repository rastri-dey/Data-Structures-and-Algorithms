/*
Source: https://leetcode.com/problems/combination-sum-ii/
Date: 20 Feb 2024
Author: Rastri Dey 
*/
/***********************************************************************************
Given a collection of candidate numbers (candidates) and a target number (target), find all unique combinations in candidates where the candidate numbers sum to target.

Each number in candidates may only be used once in the combination.

Note: The solution set must not contain duplicate combinations.

Example 1:

Input: candidates = [10,1,2,7,6,1,5], target = 8
Output: 
[
[1,1,6],
[1,2,5],
[1,7],
[2,6]
]
Example 2:

Input: candidates = [2,5,2,1,2], target = 5
Output: 
[
[1,2,2],
[5]
]

Constraints:

1 <= candidates.length <= 100
1 <= candidates[i] <= 50
1 <= target <= 30
*******************************************************************************/

// Approach: Backtracking
// Time: O(2^n) Take the candidate or not
// Space: O(n)
class Solution {
public:
    vector<vector<int>> ans;
    vector<int> curr;
    int n;
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        n = candidates.size();
        // Sort to find unique elements
        sort(candidates.begin(), candidates.end());
        backtrack(0, target, 0, candidates);
        return ans;
    }
    void backtrack(int sum, int target, int id,vector<int> candidates){
        if(sum==target){
            ans.push_back(curr);
            return;
        }
        for(int i=id; i<n; i++){
            // When we are proceeding in one branch, if the first element
            // is same as its parent, its fine, but the 2nd element shouldn't
            // be similar to the 1st element, meaning parent could be similar to 
            // just 1st child, 2nd child onwards all the branches amongst the
            // children should be different
            if(i>id && candidates[i-1]==candidates[i])
                continue;
            if(sum+candidates[i]<=target){
                curr.push_back(candidates[i]);
                backtrack(sum+candidates[i], target, i+1, candidates);
                curr.pop_back();
            }
        }
    }
};