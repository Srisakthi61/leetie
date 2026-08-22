// ──────────────────────────────────────────────────
// Problem  : 449. Serialize and Deserialize BST
// Difficulty: Medium
// Tags     : String, Tree, Depth-First Search, Breadth-First Search, Design, Binary Search Tree, Binary Tree
// Link     : https://leetcode.com/problems/serialize-and-deserialize-bst/
// Runtime  : 4 ms (beats 0%)
// Memory   : 8232000 (beats 0%)
// Language : cpp
// Copyright: (c) 2026 Srisakthi61. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

class Codec {
public:

    string serialize(TreeNode* root) {
        if (!root) return "";
        string s = "";
        serializeHelper(root, s);
        return s;
    }

    TreeNode* deserialize(string data) {
        if (data.empty()) return nullptr;
        stringstream ss(data);
        string val;
        queue<int> q;
        while (getline(ss, val, ',')) {
            q.push(stoi(val));
        }
        return deserializeHelper(q, INT_MIN, INT_MAX);
    }

private:
    void serializeHelper(TreeNode* root, string& s) {
        if (!root) return;
        s += to_string(root->val) + ",";
        serializeHelper(root->left, s);
        serializeHelper(root->right, s);
    }

    TreeNode* deserializeHelper(queue<int>& q, int lower, int upper) {
        if (q.empty()) return nullptr;
        int val = q.front();
        if (val < lower || val > upper) return nullptr;
        q.pop();
        TreeNode* root = new TreeNode(val);
        root->left = deserializeHelper(q, lower, val);
        root->right = deserializeHelper(q, val, upper);
        return root;
    }
};