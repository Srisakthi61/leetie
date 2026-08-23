// ──────────────────────────────────────────────────
// Problem  : 587. Erect the Fence
// Difficulty: Hard
// Tags     : Array, Math, Geometry, Convex Hull, Polygons
// Link     : https://leetcode.com/problems/erect-the-fence/
// Runtime  : 8 ms (beats 84%)
// Memory   : 27336000 (beats 41%)
// Language : cpp
// Copyright: (c) 2026 Srisakthi61. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

class Solution {
public:
    long long cross_product(const vector<int>& p1, const vector<int>& p2, const vector<int>& p3) {
        return (long long)(p2[0] - p1[0]) * (p3[1] - p1[1]) - (long long)(p2[1] - p1[1]) * (p3[0] - p1[0]);
    }

    vector<vector<int>> outerTrees(vector<vector<int>>& trees) {
        if (trees.size() <= 3) return trees;

        sort(trees.begin(), trees.end(), [](const vector<int>& a, const vector<int>& b) {
            if (a[0] == b[0]) return a[1] < b[1];
            return a[0] < b[0];
        });

        vector<vector<int>> hull;
        
        for (const auto& tree : trees) {
            while (hull.size() >= 2 && cross_product(hull[hull.size() - 2], hull.back(), tree) < 0) {
                hull.pop_back();
            }
            hull.push_back(tree);
        }

        for (int i = (int)trees.size() - 2; i >= 0; i--) {
            const auto& tree = trees[i];
            while (hull.size() >= 2 && cross_product(hull[hull.size() - 2], hull.back(), tree) < 0) {
                hull.pop_back();
            }
            hull.push_back(tree);
        }

        hull.pop_back();

        sort(hull.begin(), hull.end());
        hull.erase(unique(hull.begin(), hull.end()), hull.end());

        return hull;
    }
};