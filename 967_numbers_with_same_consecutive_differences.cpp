/*
Source: https://leetcode.com/problems/numbers-with-same-consecutive-differences/
Date: 9 Feb 2024
Author: Rastri Dey 
*/
/************************************************************************************
Given two integers n and k, return an array of all the integers of length n where the difference between every two consecutive digits is k. You may return the answer in any order.

Note that the integers should not have leading zeros. Integers as 02 and 043 are not allowed.

Example 1:

Input: n = 3, k = 7
Output: [181,292,707,818,929]
Explanation: Note that 070 is not a valid number, because it has leading zeroes.
Example 2:

Input: n = 2, k = 1
Output: [10,12,21,23,32,34,43,45,54,56,65,67,76,78,87,89,98]
 
Constraints:

2 <= n <= 9
0 <= k <= 9
*************************************************************************************/
// Approach: Backtracking (Uses a Recursive Tree DFS)

// Time: O(2^n) ~ O(9*2^(n-1)), Count the number of nodes, requires to be traversed
//  n>1 Depth of tree is until n(number of digits)
//  Unit digit can have 0-9 -> 9
//  Tens digit can have 9*2. For every unit digit there are at most 
//  2 possibilities (+k/-k). For hundreds digit, the number of 
//  variations from tens digit are there, for each of those variations 
//  there are 2 possibilities : 2*(9*2), likewise for 1000th digit: 2*(9*2*2)
//  Hence for n digits: 9*2^(n-1) 

// Space: O(n) Recursive stack is of depth n, no other space used 

class Solution {
public:
    vector<int> numsSameConsecDiff(int n, int k) {
      vector<int> ans;
      // Unit digit is the only digit in our control, once unit digit
      // is decided rest of the digits follow +k/-k,
      // unit digit can be between 0-9
      for(int i=0; i<10; i++){
         backtrack(i, 0, k, n, 0, ans);
      }
      return ans;
    }
  void backtrack(int id, int mult, int k, int n, int num, vector<int>&ans){
      // Set a multiplier which is bound to n-1 digits
    if(mult==n){
        if(find(ans.begin(), ans.end(), num)==ans.end())
            ans.push_back(num);
      return;
    }
    // If the multiplier is the front digit it can't be 0
    // If the multiplier is not a front digit, allow it to be 0 - 9
    // 0<=id+k<=9 for (mult!=n-1)
    if((mult==n-1 && id+k>0 && id+k<10) || (mult!=n-1 && id+k>=0 && id+k<10)){
      num += (id+k)*pow(10,mult);
      backtrack(id+k, mult+1, k, n, num, ans);
      num -= (id+k)*pow(10,mult);
    }
    // 0<=id-k<=9, check if id-k is a valid digit
    if((mult==n-1 && id-k>0 && id-k<10) || (mult!=n-1 && id-k>=0 && id-k<10)){
      num += (id-k)*pow(10,mult);
      backtrack(id-k, mult+1, k, n, num, ans);
      num -= (id-k)*pow(10,mult);
    }
    return;
  }
};