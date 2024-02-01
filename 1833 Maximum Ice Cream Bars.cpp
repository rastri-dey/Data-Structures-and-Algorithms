/*
Source: https://leetcode.com/problems/maximum-ice-cream-bars/
Date: 31 Jan 2024
Author: Rastri Dey 
*/
/***********************************************************************************************
Problem:
It is a sweltering summer day, and a boy wants to buy some ice cream bars.
At the store, there are n ice cream bars. You are given an array costs of length n, where costs[i] is the price of the ith ice cream bar in coins. The boy initially has coins coins to spend, and he wants to buy as many ice cream bars as possible. 
Note: The boy can buy the ice cream bars in any order.
Return the maximum number of ice cream bars the boy can buy with coins coins.
You must solve the problem by counting sort.

Example 1:

Input: costs = [1,3,2,4,1], coins = 7
Output: 4
Explanation: The boy can buy ice cream bars at indices 0,1,2,4 for a total price of 1 + 3 + 2 + 1 = 7.
Example 2:

Input: costs = [10,6,8,7,7,8], coins = 5
Output: 0
Explanation: The boy cannot afford any of the ice cream bars.
Example 3:

Input: costs = [1,6,3,1,2,5], coins = 20
Output: 6
Explanation: The boy can buy all the ice cream bars for a total price of 1 + 6 + 3 + 1 + 2 + 5 = 18.

Constraints:

costs.length == n
1 <= n <= 105
1 <= costs[i] <= 105
1 <= coins <= 108
****************************************************************************************************/

// Approach: Counting Sort & Greedy Algorithm
// Time: O(n+m): n is length of input array & m is maximum element
// Space Complexity: O(m)
class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
       // Create a count array: Find the frequency of each element and store the frequency as value at the element index
       int n = *max_element(costs.begin(), costs.end());
       vector<int> count(n+1, 0);
       for(int c: costs){
           count[c]++;
       } 

       int ans = 0;
       for(int i=1; i<n+1 && coins>0; i++){
            //If the coins left is less than the money then break
            if(coins<i)
                break;
            //Minimum to see leftover coins are lesser or not than count[i]
            int cnt = min(count[i], coins/i);
            ans+=cnt;
            coins-=i*cnt;
       }
       return ans;
    }
};