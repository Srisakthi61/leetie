// ──────────────────────────────────────────────────
// Problem  : 2265. Count Nodes Equal to Average of Subtree
// Difficulty: Medium
// Tags     : Tree, Depth-First Search, Binary Tree
// Link     : https://leetcode.com/problems/count-nodes-equal-to-average-of-subtree/
// Runtime  : 0 ms (beats 100%)
// Memory   : 15600000 (beats 97%)
// Language : cpp
// Copyright: (c) 2026 Srisakthi61. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

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
private:
    pair<int, int> dfs(TreeNode* node, int& countValid) {
        if (!node) {
            return {0, 0};
        }
        
        auto leftResult = dfs(node->left, countValid);
        auto rightResult = dfs(node->right, countValid);
        
        int currentSum = node->val + leftResult.first + rightResult.first;
        int currentCount = 1 + leftResult.second + rightResult.second;
        
        if (currentSum / currentCount == node->val) {
            countValid++;
        }
        
        return {currentSum, currentCount};
    }

public:
    int averageOfSubtree(TreeNode* root) {
        int countValid = 0;
        dfs(root, countValid);
        return countValid;
    }
};