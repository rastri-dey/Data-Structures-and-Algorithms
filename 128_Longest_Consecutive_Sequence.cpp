/*
Source: https://leetcode.com/problems/longest-consecutive-sequence/
Date: 11 Feb 2024
Author: Rastri Dey 
*/
/******************************************************************************
Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.

You must write an algorithm that runs in O(n) time.

Example 1:

Input: nums = [100,4,200,1,3,2]
Output: 4
Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.
Example 2:

Input: nums = [0,3,7,2,5,8,4,6,0,1]
Output: 9

Constraints:

0 <= nums.length <= 105
-109 <= nums[i] <= 109
*************************************************************************************/

// Approach: Hashset intelligent sequence build
// Time: O(n), n=nums.size()
// Space: O(n)
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        // Create a Hashset for all nums
        unordered_set<int> st;
        for(int num: nums){
            st.insert(num);
        }
        int ans = 0;
        for(int num: st){
            // Current num is the lowest num in the sequence
            // Number 1 lower (num-1) does not exist
            if(st.find(num-1)==st.end()){
                int curr = num+1;
                int currLen = 1;
                while(st.find(curr)!=st.end()){
                    curr++;
                    currLen++;
                }
                ans = max(ans,currLen);
            }
        }
        return ans;
    }
};