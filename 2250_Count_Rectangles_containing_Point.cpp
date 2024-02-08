/*
Source: https://leetcode.com/problems/count-number-of-rectangles-containing-each-point/
Date: 8 Feb 2024
Author: Rastri Dey 
*/
/****************************************************************************
You are given a 2D integer array rectangles where rectangles[i] = [li, hi] indicates that ith rectangle has a length of li and a height of hi. You are also given a 2D integer array points where points[j] = [xj, yj] is a point with coordinates (xj, yj).

The ith rectangle has its bottom-left corner point at the coordinates (0, 0) and its top-right corner point at (li, hi).

Return an integer array count of length points.length where count[j] is the number of rectangles that contain the jth point.

The ith rectangle contains the jth point if 0 <= xj <= li and 0 <= yj <= hi. Note that points that lie on the edges of a rectangle are also considered to be contained by that rectangle.

Example 1:

Input: rectangles = [[1,2],[2,3],[2,5]], points = [[2,1],[1,4]]
Output: [2,1]
Explanation: 
The first rectangle contains no points.
The second rectangle contains only the point (2, 1).
The third rectangle contains the points (2, 1) and (1, 4).
The number of rectangles that contain the point (2, 1) is 2.
The number of rectangles that contain the point (1, 4) is 1.
Therefore, we return [2, 1].
Example 2:


Input: rectangles = [[1,1],[2,2],[3,3]], points = [[1,3],[1,1]]
Output: [1,3]
Explanation:
The first rectangle contains only the point (1, 1).
The second rectangle contains only the point (1, 1).
The third rectangle contains the points (1, 3) and (1, 1).
The number of rectangles that contain the point (1, 3) is 1.
The number of rectangles that contain the point (1, 1) is 3.
Therefore, we return [1, 3].
 

Constraints:

1 <= rectangles.length, points.length <= 5 * 104
rectangles[i].length == points[j].length == 2
1 <= li, xj <= 109
1 <= hi, yj <= 100
All the rectangles are unique.
All the points are unique.
*******************************************************************/

// Approach: Binary Search, Hashmap
// Time: O(n+100+m*100*logn), n=rectangles.size(), m=points.size()
// Space: O(n)
class Solution {
public:
    vector<int> countRectangles(vector<vector<int>>& rectangles, vector<vector<int>>& points) {
        // We have to sort the rectangles in some manner & perform binary search
        // for each point
        // Create an unordered_map based on heights and vector of sorted width for that height
        unordered_map<int, vector<int>> mp;
        for(vector<int> r: rectangles){
            // Key will be height, value will all widths of that height
            mp[r[1]].push_back(r[0]);
        }
        for(auto [h,ws] : mp){
            //Sort for each height the corresponding widths: ws is vector of all width
            sort(mp[h].begin(), mp[h].end());
        }
        // Iterate through the points
        vector<int> ans;
        for(vector<int> v: points){
            int x = v[0], y = v[1];
            int cnt = 0;
            for(int h=y; h<=100; h++){
                // Find out the right bound of the point satisfied for 
                // a given height h, repeat it for all y<=h
                if(mp.find(h)!=mp.end())
                    cnt += mp[h].end() - lower_bound(mp[h].begin(), mp[h].end(),x);
                
            }
            
            ans.push_back(cnt);
        }
        return ans;
    }
   
};