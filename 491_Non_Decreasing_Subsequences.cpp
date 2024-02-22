/*
Source: https://leetcode.com/problems/non-decreasing-subsequences/
Date: 22 Feb 2024
Author: Rastri Dey 
*/
/*********************************************************************************
Given an integer array nums, return all the different possible non-decreasing subsequences of the given array with at least two elements. You may return the answer in any order.

Example 1:

Input: nums = [4,6,7,7]
Output: [[4,6],[4,6,7],[4,6,7,7],[4,7],[4,7,7],[6,7],[6,7,7],[7,7]]
Example 2:

Input: nums = [4,4,3,2,1]
Output: [[4,4]] 

Constraints:

1 <= nums.length <= 15
-100 <= nums[i] <= 100

*********************************************************************************/

//Approach: Backtracking

// Time: O(2^N * N^2) For an array of length N, for every number we can either
// select or reject it, so all combinations would be 2^N. In C++, hash set
// is internally implemented to have complexity of N^2, so everytime we
// are pushing it in set and maximum N times we can push it

// Space: O(N) Depth of the tree is N, so recursive stack space of N
// ans is having space of 2^N, so if we combine ans, then to reach 1 subsequence
// N stack space is required, for 2^N subsequence 2^N*N space is required
// But here we are not considering ans in space complexity

class Solution {
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<int> curr;
        //Create a set to avoid duplicate vectors
        set<vector<int>> ans;
        backtrack(0, nums, curr,ans);
        return vector(ans.begin(),ans.end());
    }
    void backtrack(int id, vector<int>& nums, vector<int>&curr, set<vector<int>>& ans){
        //Include in the ans if subsequence size>=2
        if(curr.size()>=2){
            ans.insert(curr);
        }
        //Base case
        if(id==nums.size())
            return;

        for(int i=id, n=nums.size(); i<n; i++){
            //Take the number only when its non-decreasing
            if((curr.size()>0 && nums[i]<curr.back()))
                continue;
            // Recursion through tree 
            curr.push_back(nums[i]);
            backtrack(i+1, nums, curr,ans);
            curr.pop_back();
        }
        return;
    }
};