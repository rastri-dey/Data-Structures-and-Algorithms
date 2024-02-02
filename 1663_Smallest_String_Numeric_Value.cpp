/*
Source: https://leetcode.com/problems/smallest-string-with-a-given-numeric-value/
Date: 2 Feb 2024
Author: Rastri Dey 
*/
/*****************************************************************************
The numeric value of a lowercase character is defined as its position (1-indexed) in the alphabet, so the numeric value of a is 1, the numeric value of b is 2, the numeric value of c is 3, and so on.
The numeric value of a string consisting of lowercase characters is defined as the sum of its characters' numeric values. For example, the numeric value of the string "abe" is equal to 1 + 2 + 5 = 8.
You are given two integers n and k. Return the lexicographically smallest string with length equal to n and numeric value equal to k.
Note that a string x is lexicographically smaller than string y if x comes before y in dictionary order, that is, either x is a prefix of y, or if i is the first position such that x[i] != y[i], then x[i] comes before y[i] in alphabetic order.

Example 1:
Input: n = 3, k = 27
Output: "aay"
Explanation: The numeric value of the string is 1 + 1 + 25 = 27, and it is the smallest string with such a value and length equal to 3.

Example 2:
Input: n = 5, k = 73
Output: "aaszz"
 
Constraints:
1 <= n <= 105

n <= k <= 26 * n
******************************************************************************/

// Approach: Greedy Start from Right 
// Time: O(n)
// Space: O(1)

class Solution {
public:
    string getSmallestString(int n, int k) {

        // Atleast the word will have all a's
        string v(n,'a'); 

        // Existing sum = n, remaining sum k-=n
        k-=n;

        // Start with rightmost index
        int j=n-1;

        // Keep iterating until remaining sum = 0
        while(k>0){
            // Bound the character limit to 26 & remaning value of sum for jth index
            int m = min(v[j]-'a'+1+k, 26);

            // After setting the jth index value, 
            // reduce the sum by k-=sum until jth character from right
            k -= (m-(v[j]-'a'+1));

            // Replace current jth character with maximum value it can hold
            // between leftover sum & 26 
            v[j] = (char)(m-1+'a');

            // Reduce the jth index towards left
            j--;
        }
        return v;
    }
};