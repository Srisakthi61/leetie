// ──────────────────────────────────────────────────
// Problem  : 987. Vertical Order Traversal of a Binary Tree
// Difficulty: Hard
// Tags     : Hash Table, Tree, Depth-First Search, Breadth-First Search, Sorting, Binary Tree
// Link     : https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/
// Runtime  : 0 ms (beats 0%)
// Memory   : 8640000 (beats 0%)
// Language : cpp
// Copyright: (c) 2026 Srisakthi61. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, map<int, multiset<int>>> mp;
        queue<pair<TreeNode*, pair<int, int>>> q;
        q.push({root, {0, 0}});
        
        while (!q.empty()) {
            auto [node, pos] = q.front();
            q.pop();
            int col = pos.first;
            int row = pos.second;
            
            mp[col][row].insert(node->val);
            
            if (node->left) {
                q.push({node->left, {col - 1, row + 1}});
            }
            if (node->right) {
                q.push({node->right, {col + 1, row + 1}});
            }
        }
        
        vector<vector<int>> result;
        for (auto& [col, rowMap] : mp) {
            vector<int> colVec;
            for (auto& [row, st] : rowMap) {
                colVec.insert(colVec.end(), st.begin(), st.end());
            }
            result.push_back(colVec);
        }
        
        return result;
    }
};