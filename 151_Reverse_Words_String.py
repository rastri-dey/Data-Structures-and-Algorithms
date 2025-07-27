'''
Source: https://leetcode.com/problems/reverse-words-in-a-string/description/
Date: 01 Jul 2025
Author: Rastri Dey 

************************************************************************************

Given an input string s, reverse the order of the words.

A word is defined as a sequence of non-space characters. The words in s will be separated by at least one space.

Return a string of the words in reverse order concatenated by a single space.

Note that s may contain leading or trailing spaces or multiple spaces between two words. The returned string should only have a single space separating the words. Do not include any extra spaces.

Example 1:

Input: s = "the sky is blue"
Output: "blue is sky the"
Example 2:

Input: s = "  hello world  "
Output: "world hello"
Explanation: Your reversed string should not contain leading or trailing spaces.
Example 3:

Input: s = "a good   example"
Output: "example good a"
Explanation: You need to reduce multiple spaces between two words to a single space in the reversed string.
 

Constraints:

1 <= s.length <= 104
s contains English letters (upper-case and lower-case), digits, and spaces ' '.
There is at least one word in s.

************************************************************************************
'''

# Approach: Reverse whole string and then reverse each word
# Time: O(N) Going through s twice
# Space: O(N) Creating list

class Solution:
    def spaces(self, s: str) -> list:
        f = 0
        l = len(s)-1

        # Remove spaces in the beginning
        while(f<=l and s[f]==" "):
            f+=1
        
        # Remove spaces in the end
        while(f<=l and s[l]==" "):            
            l-=1

        line = []
        while(f<=l):
            if (s[f] != " "):
                line.append(s[f])

            # Add only 1 space if last character added was not space
            # and current character is space
            elif (line[-1] != " "):
                line.append(s[f])

            f+=1

        return line

    def reverse(self, line: list, f: int, l: int) -> None:
        while(f<l):
            temp = line[f]
            line[f] = line[l]
            line[l] = temp
            f+=1
            l-=1


    def reverseWords(self, s: str) -> str:        
        line = self.spaces(s)
        self.reverse(line, 0, len(line)-1)
        
        curr = 0
        wi = 0
        n = len(line)

        # Reverse words in string
        while(curr<n):
            while(curr<n and line[curr]!=" "):
                curr+=1
            self.reverse(line, wi, curr-1)
            wi = curr+1
            curr+=1

        return "".join(line)
    
# Approach: Using Deque
# Time: O(N)
# Space: O(N)

from collections import deque

class Solution:
    def reverseWords(self, s: str) -> str:
        l, r = 0, len(s)-1

        # Remove leading space
        while(l<=r and s[l]==' '):
            l+=1

        # Remove trailing space
        while(l<=r and s[r]==' '):
            r-=1

        # d is Deque of single string
        # word is list of characters
        word, d = [], deque()

        while(l<=r):
            if (s[l]==' ' and word):
                # join the list of characters in a single string
                # ['h', 'e', 'l', 'l', 'o'], "".join(word) would 
                # result  in the string "hello"
                d.appendleft("".join(word))
                word = []

            elif(s[l]!=' '):
                word.append(s[l])
            l+=1
        d.appendleft("".join(word))
        return " ".join(d)
       