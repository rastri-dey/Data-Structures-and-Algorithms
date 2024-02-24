/*
Source: https://leetcode.com/problems/restore-ip-addresses/
Date: 24 Feb 2024
Author: Rastri Dey 
*/
/***********************************************************************
A valid IP address consists of exactly four integers separated by single dots. Each integer is between 0 and 255 (inclusive) and cannot have leading zeros.

For example, "0.1.2.201" and "192.168.1.1" are valid IP addresses, but "0.011.255.245", "192.168.1.312" and "192.168@1.1" are invalid IP addresses.
Given a string s containing only digits, return all possible valid IP addresses that can be formed by inserting dots into s. You are not allowed to reorder or remove any digits in s. You may return the valid IP addresses in any order.

Example 1:

Input: s = "25525511135"
Output: ["255.255.11.135","255.255.111.35"]
Example 2:

Input: s = "0000"
Output: ["0.0.0.0"]
Example 3:

Input: s = "101023"
Output: ["1.0.10.23","1.0.102.3","10.1.0.23","10.10.2.3","101.0.2.3"]
 
Constraints:

1 <= s.length <= 20
s consists of digits only.
************************************************************************/

class Solution {
public:
    int n;
    vector<string> ans;
    vector<string> restoreIpAddresses(string s) { 
        n = s.size();
        if(n>12) return ans;
        string curr;
        backtrack(0,0,curr,s);
        return ans;
    }
    void backtrack(int idx, int parts, string curr, string s){
        // 4 parts we have created & checked until last index
        if(parts==4 && idx==n){
            curr.pop_back();
            ans.push_back(curr);
            return;
        }
        // Only 3 charcaters at a time is possible
        if(idx+1<=n)
            backtrack(idx+1, parts+1, curr+s.substr(idx,1)+".",s);
        if(idx+2<=n && valid(s.substr(idx,2)))
            backtrack(idx+2, parts+1, curr+s.substr(idx,2)+".",s);
        if(idx+3<=n && valid(s.substr(idx,3)))
            backtrack(idx+3, parts+1, curr+s.substr(idx,3)+".",s);
 
    }
    bool valid(string str){
        // No leading 0
        if(str[0]=='0'){
            return false;
        }
        // Within 255
        if(stoi(str)>255){
            return false;
        }
        return true;
    }
};