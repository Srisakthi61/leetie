// ──────────────────────────────────────────────────
// Problem  : 654. Maximum Binary Tree
// Difficulty: Medium
// Tags     : Array, Divide and Conquer, Stack, Tree, Monotonic Stack, Binary Tree, Cartesian Tree
// Link     : https://leetcode.com/problems/maximum-binary-tree/
// Runtime  : 0 ms (beats 0%)
// Memory   : 8188000 (beats 0%)
// Language : cpp
// Copyright: (c) 2026 Srisakthi61. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

class Solution {
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return build(nums, 0, nums.size() - 1);
    }

private:
    TreeNode* build(const vector<int>& nums, int left, int right) {
        if (left > right) {
            return nullptr;
        }

        int maxIdx = left;
        for (int i = left + 1; i <= right; ++i) {
            if (nums[i] > nums[maxIdx]) {
                maxIdx = i;
            }
        }

        TreeNode* node = new TreeNode(nums[maxIdx]);
        node->left = build(nums, left, maxIdx - 1);
        node->right = build(nums, maxIdx + 1, right);

        return node;
    }
};