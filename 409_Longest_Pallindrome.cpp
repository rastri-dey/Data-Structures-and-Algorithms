/*
Source: https://leetcode.com/problems/longest-palindrome/
Date: 1 Feb 2024
Author: Rastri Dey 
*/
/*****************************************************************************
Given a string s which consists of lowercase or uppercase letters, return the length of the longest palindrome that can be built with those letters.
Letters are case sensitive, for example, "Aa" is not considered a palindrome here.

Example 1:
Input: s = "abccccdd"
Output: 7
Explanation: One longest palindrome that can be built is "dccaccd", whose length is 7.

Example 2:
Input: s = "a"
Output: 1
Explanation: The longest palindrome that can be built is "a", whose length is 1.
 
Constraints:

1 <= s.length <= 2000
s consists of lowercase and/or uppercase English letters only. 
*****************************************************************************/


// Approach: Greedy, Hashset
// Time : O(n) where n = s.size()
// Space : O(n) or O(1) as maximum space if all characters are odd = 26*2
class Solution {
public:
    int longestPalindrome(string s) {
        // Create a HashSet of characters
        unordered_set<char> st; 
       // Use hashset to add the odd frequency of character
       // If the character is in even frequency, then remove it
       int ans = 0;
        for(char c: s){
            // Character appears in mutiple of 2 (even times)
            if(st.find(c)!=st.end()){
                st.erase(c);
                ans += 2; // Add twice for both previous and current counts
            }else{
                st.insert(c);
            }
        }
        // If hashset is not empty, 
        // then there is atleast 1 odd frequency character
        if(!st.empty())
            return ans+1;
       // If hashset is empty in the end,
       // then all characters are in even frequency      
        return ans;
    }
};