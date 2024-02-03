/*
Source: https://leetcode.com/problems/optimal-partition-of-string/
Date: 3 Feb 2024
Author: Rastri Dey 
*/
/***************************************************************************************
Given a string s, partition the string into one or more substrings such that the characters in each substring are unique. That is, no letter appears in a single substring more than once.

Return the minimum number of substrings in such a partition.

Note that each character should belong to exactly one substring in a partition.

Example 1:

Input: s = "abacaba"
Output: 4
Explanation:
Two possible partitions are ("a","ba","cab","a") and ("ab","a","ca","ba").
It can be shown that 4 is the minimum number of substrings needed.
Example 2:

Input: s = "ssssss"
Output: 6
Explanation:
The only valid partition is ("s","s","s","s","s","s").

Constraints:
1 <= s.length <= 105
s consists of only English lowercase letters.
****************************************************************************************/
// Approach: Greedy
// Time: O(n)
// Space: O(1)
class Solution {
public:
    int partitionString(string s) {
        // Store the index of characters
        vector<int> v(26,-1);
        // Initiate as first string
        int ans=1; 
        // First index of current substring
        int initStr = 0;
        for(int i=0, n=s.size(); i<n; i++){
            char c = s[i];
            // current character is already present in the current substring
            // If character is present in the past than the current string, 
            // then its fine, but if the character is present after the starting 
            // index of current first index of current string 
            if(v[c-'a']>=initStr){
                v[c-'a'] = i;
                initStr = i;
                ans++;
            }else{
                v[c-'a'] = i;
            }
        }
        return ans;
    }
};
