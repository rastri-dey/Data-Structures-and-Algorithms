/*
Source: https://leetcode.com/problems/maximize-sum-of-array-after-k-negations/
Date: 2 Feb 2024
Author: Rastri Dey 
*/
/***************************************************************************************
Given an integer array nums and an integer k, modify the array in the following way:

choose an index i and replace nums[i] with -nums[i].
You should apply this process exactly k times. You may choose the same index i multiple times.

Return the largest possible sum of the array after modifying it in this way.

Example 1:
Input: nums = [4,2,3], k = 1
Output: 5
Explanation: Choose index 1 and nums becomes [4,-2,3].
Example 2:
Input: nums = [3,-1,0,2], k = 3
Output: 6
Explanation: Choose indices (1, 2, 2) and nums becomes [3,1,0,2].

Example 3:
Input: nums = [2,-3,-1,5,-4], k = 2
Output: 13
Explanation: Choose indices (1, 4) and nums becomes [2,3,-1,5,4].
 
Constraints:
1 <= nums.length <= 104
-100 <= nums[i] <= 100
1 <= k <= 104
******************************************************************************************/
// Approach: Priority Queue with Greedy algorithm
// Time: O(klog n) Push & pop operations are k times for size n priority queue
// Space: O(n) Priority queue size is n
class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        // Find sum of all integers
        int sum = 0;
        for(int ni: nums)
            sum+=ni;
        // Ascending order Priority Queue
        priority_queue<int, vector<int>, greater<int>> q(nums.begin(), nums.end());
        // Iterate for k negations
        while(k>0){
            int qi = q.top();
            // Negate twice: Once for making it 0 and then making it -ve
            sum -= 2*qi;        
            q.pop();
            // push the -ve value again and 
            // make the array sorted again through Priority Queue
            q.push(-qi);        
            k--;
        }
        return sum;
    }
};