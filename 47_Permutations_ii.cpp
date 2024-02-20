/*
Source: https://leetcode.com/problems/permutations-ii/description/
Date: 20 Feb 2024
Author: Rastri Dey 
*/
/***************************************************************************
Given a collection of numbers, nums, that might contain duplicates, return all possible unique permutations in any order.

Example 1:

Input: nums = [1,1,2]
Output:
[[1,1,2],
 [1,2,1],
 [2,1,1]]
Example 2:

Input: nums = [1,2,3]
Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]

Constraints:

1 <= nums.length <= 8
-10 <= nums[i] <= 10
****************************************************************************/
// Approach: Backtracking
// Time: O(Sum(P(N,k))), Sum is summation from k=1 to N,
// for all permutations of P(N,k)
// Space: O(N)
class Solution {
public:
    vector<int> curr;
    vector<vector<int>> ans;
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        int n = nums.size();
        // create a hashtable for unique numbers 
        unordered_map<int, int> mp;
        for(int k: nums){
            mp[k]++;
        }
        backtrack(mp, n);
        return ans;
    }
    void backtrack(unordered_map<int, int> mp, int n){
        if(curr.size()==n){
            ans.push_back(curr);
            return;
        }
        for(auto [key, val]: mp){
            // If the val has become 0, 
            // all the occurences along that branch has been already utilized
            if(val==0) continue;
            curr.push_back(key);
            // Reduce 1 counter
            mp[key]--; 
            backtrack(mp, n);
            curr.pop_back();
            // Increase counter for that number 
            // to be considered again for different branch
            mp[key]++;
        }
        return;
    }
};