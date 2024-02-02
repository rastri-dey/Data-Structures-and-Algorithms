/*
Source: https://leetcode.com/problems/longest-zigzag-path-in-a-binary-tree/
Date: 25 Nov 2023
Author: Rastri Dey 
*/
/*****************************************************************************
You are given the root of a binary tree.

A ZigZag path for a binary tree is defined as follow:

Choose any node in the binary tree and a direction (right or left).
If the current direction is right, move to the right child of the current node; otherwise, move to the left child.
Change the direction from right to left or from left to right.
Repeat the second and third steps until you can't move in the tree.
Zigzag length is defined as the number of nodes visited - 1. (A single node has a length of 0).

Return the longest ZigZag path contained in that tree.
Example 1:


Input: root = [1,null,1,1,1,null,null,1,1,null,1,null,null,null,1]
Output: 3
Explanation: Longest ZigZag path in blue nodes (right -> left -> right).
Example 2:

Input: root = [1,1,1,null,1,null,null,1,1,null,1]
Output: 4
Explanation: Longest ZigZag path in blue nodes (left -> right -> left -> right).
Example 3:

Input: root = [1]
Output: 0
 
Constraints:

The number of nodes in the tree is in the range [1, 5 * 104].
1 <= Node.val <= 100
******************************************************************************/
// Approach: DFS Binary Tree
// Time : O(n) where n = nodes
// Space : O(n) Recursion Stack

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int maxPath;
    static constexpr int LEFT = 0;
    static constexpr int RIGHT = 1;
    int longestZigZag(TreeNode* root) {
        maxPath = 0;
        dfs(root,RIGHT,0);
        dfs(root,LEFT,0);
        return maxPath;
    }
    void dfs(TreeNode* node, int dir, int currPath){
        if(!node) return;

        maxPath = max(maxPath, currPath);

        if(dir==LEFT){
            dfs(node->right, 1-dir, currPath+1);
            dfs(node->left, 1-dir, 0);
        }
        
        if(dir==RIGHT){
            dfs(node->left, 1-dir, currPath+1);
            dfs(node->right, 1-dir, 0);
        }
        
        return;
    }
};