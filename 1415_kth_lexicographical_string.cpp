/*
Source: https://leetcode.com/problems/the-k-th-lexicographical-string-of-all-happy-strings-of-length-n/
Date: 21 Feb 2024
Author: Rastri Dey 
*/
/****************************************************************************************
A happy string is a string that:

consists only of letters of the set ['a', 'b', 'c'].
s[i] != s[i + 1] for all values of i from 1 to s.length - 1 (string is 1-indexed).
For example, strings "abc", "ac", "b" and "abcbabcbcb" are all happy strings and strings "aa", "baa" and "ababbc" are not happy strings.

Given two integers n and k, consider a list of all happy strings of length n sorted in lexicographical order.

Return the kth string of this list or return an empty string if there are less than k happy strings of length n.

Example 1:

Input: n = 1, k = 3
Output: "c"
Explanation: The list ["a", "b", "c"] contains all happy strings of length 1. The third string is "c".
Example 2:

Input: n = 1, k = 4
Output: ""
Explanation: There are only 3 happy strings of length 1.
Example 3:

Input: n = 3, k = 9
Output: "cab"
Explanation: There are 12 different happy string of length 3 ["aba", "abc", "aca", "acb", "bab", "bac", "bca", "bcb", "cab", "cac", "cba", "cbc"]. You will find the 9th string = "cab"
 
Constraints:

1 <= n <= 10
1 <= k <= 100
*****************************************************************************************/
// Approach: Backtracking

// Time: O(3*2^(N-1)), if K=N all the possibilities in worst case would be 3*2^(N-1)
// for 1st character there are 3 possibilities
// next character onwards there are 2 possibilities, as no 2 adjacent characters could be same

// Space: O(N*K) Depth of tree could be maximum N, that will take Recursive Stack space. 
// Due to ans size, there would be N*K space, so worst case N*K

class Solution {
public:
    string getHappyString(int n, int k) {
        vector<string> ans;
        string curr = "\0";
        backtrack(ans, curr, n, k);
        if(ans.size()==k)
            return ans.back();

        return "";
    }
    void backtrack(vector<string> &ans, string &curr, int n, int k){
        // Limit the ans vector to k
        if(ans.size()==k){
            return;
        }
        // Limit the current string size to n
        if(curr.size()==n){
            ans.push_back(curr);
            return;
        }
        for(char c: {'a','b','c'}){
            // If last 2 characters are similar do not proceed
            if(curr.size()>0 && curr.back()==c) continue;
            curr.push_back(c);
            backtrack(ans, curr, n, k);
            curr.pop_back();
        }
        return;
    }
};