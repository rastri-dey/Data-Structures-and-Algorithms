/*
Source: https://leetcode.com/problems/largest-palindromic-number/
Date: 4 Feb 2024
Author: Rastri Dey 
*/
/*********************************************************************************
You are given a string num consisting of digits only.

Return the largest palindromic integer (in the form of a string) that can be formed using digits taken from num. It should not contain leading zeroes.

Notes:

You do not need to use all the digits of num, but you must use at least one digit.
The digits can be reordered.
 
Example 1:

Input: num = "444947137"
Output: "7449447"
Explanation: 
Use the digits "4449477" from "444947137" to form the palindromic integer "7449447".
It can be shown that "7449447" is the largest palindromic integer that can be formed.
Example 2:

Input: num = "00009"
Output: "9"
Explanation: 
It can be shown that "9" is the largest palindromic integer that can be formed.
Note that the integer returned should not contain leading zeroes.
 
Constraints:
1 <= num.length <= 105
num consists of digits.
************************************************************************************/
// Approach: Greedy
// Time: O(n) n = nums.size(), reverse takes O(n) time & O(1) space
// Space: O(1)
class Solution {
public:
    string largestPalindromic(string num) {
        // Calculate the frrequency of each digit
        vector<int> count(10,0);
        int n = num.size();
        for(int i=0; i<n; i++){
            int d = num[i]-'0';
            count[d]++;
        }
        // Design the pallindrome in 2 parts of front & back which are equivalent
        string front; 
        string back;
        int cntr = -1;
        // Largest pallindrome should start from 9
        for(int i=9; i>=0; i--){
            // If count>1 & i>0 or count>1 we can insert some 0s in the middle
            while((count[i]>1 && i>0) || (count[i]>1 && !front.empty() && i==0)){
                front += '0'+i;
                back += '0'+i;
                count[i] -= 2;
            }
            // Find the maximum center value of 1 in frequency
            if(count[i]==1) cntr = max(cntr,i);
        }
        // Update center value wrt highest num of 1 freq in string form
        string c = "\0";
        if(cntr!=-1)
            c += cntr + '0';
        // If so far no front, no back, no center is there but num is 
        // minimum of 1 length so there must be some number of 0s, return 0
        if(front.empty() && back.empty() && cntr==-1) return "0";
        // Reverse the back for pallindrom
        reverse(back.begin(), back.end());

        return front + c + back;
    }
};