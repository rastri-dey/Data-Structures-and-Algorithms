/*
Source: https://leetcode.com/problems/first-unique-character-in-a-string/
Date: 10 Feb 2024
Author: Rastri Dey 
*/
/*******************************************************************************
Given a string s, find the first non-repeating character in it and return its index. If it does not exist, return -1.

Example 1:

Input: s = "leetcode"
Output: 0
Example 2:

Input: s = "loveleetcode"
Output: 2
Example 3:

Input: s = "aabb"
Output: -1

Constraints:

1 <= s.length <= 105
s consists of only lowercase English letters.
********************************************************************************/

// Approach: Linear pass
// Time: O(n) n=s.size()
// Space: O(1) limited by 26 characters in contraints
class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, int> mp;
        // Count frequency
        for(char c: s){
            mp[c]++;
        }
        // Go through the string s to check frequency for each character
        for(int i=0, n=s.size(); i<n; i++){
            if(mp[s[i]]==1)
                return i;
        }
        return -1;
    }
};