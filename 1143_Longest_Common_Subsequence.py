'''
Source: https://leetcode.com/problems/longest-common-subsequence/description/
Date: 26 May 2025
Author: Rastri Dey 

************************************************************************************

Given two strings text1 and text2, return the length of their longest common subsequence. If there is no common subsequence, return 0.

A subsequence of a string is a new string generated from the original string with some characters (can be none) deleted without changing the relative order of the remaining characters.

For example, "ace" is a subsequence of "abcde".
A common subsequence of two strings is a subsequence that is common to both strings.

Example 1:

Input: text1 = "abcde", text2 = "ace" 
Output: 3  
Explanation: The longest common subsequence is "ace" and its length is 3.
Example 2:

Input: text1 = "abc", text2 = "abc"
Output: 3
Explanation: The longest common subsequence is "abc" and its length is 3.
Example 3:

Input: text1 = "abc", text2 = "def"
Output: 0
Explanation: There is no such common subsequence, so the result is 0.
 

Constraints:

1 <= text1.length, text2.length <= 1000
text1 and text2 consist of only lowercase English characters.

************************************************************************************

# Approach: Top Down recursive memoization
# Time: O(M*N)
# Space: O(M*N)
'''

from functools import cache

class Solution:
    def longestCommonSubsequence(self, text1: string, text2: string) -> int:
        @cache
        def dp(i: int, j: int) -> int:

            if i==len(text1) or j==len(text2):
                return 0

            # If they are same, add 1 and go to the next pointer for both strings
            if text1[i] == text2[j]:
                return dp(i+1,j+1) + 1

            # If they are not same, perform addition of one character at a time
            # from both the strings and take the longest subsequence among
            # the 2 strings post addition of one character one at a time 
            
            return max(dp(i+1,j), dp(i, j+1))

        # start from 1st character
        return dp(0,0)
    
# Approach: Bottom Up
# Time: O(M*N)
# Space: O(M*N)
    
class Solution:
    def longestCommonSubsequence(self, text1: str, text2: str) -> int:
        n = len(text1)
        m = len(text2)
        dp = [[0] * (m + 1) for _ in range(n + 1)]
        
        for i in range(n - 1, -1, -1):
            for j in range(m - 1, -1, -1):
                if text1[i] == text2[j]:
                    dp[i][j] = 1 + dp[i + 1][j + 1]
                else:
                    dp[i][j] = max(dp[i + 1][j], dp[i][j + 1])
        
        return dp[0][0]