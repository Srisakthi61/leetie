// ──────────────────────────────────────────────────
// Problem  : 952. Largest Component Size by Common Factor
// Difficulty: Hard
// Tags     : Array, Hash Table, Math, Union-Find, Number Theory, Prime Factorization
// Link     : https://leetcode.com/problems/largest-component-size-by-common-factor/
// Runtime  : 151 ms (beats 46%)
// Memory   : 55344000 (beats 77%)
// Language : cpp
// Copyright: (c) 2026 Srisakthi61. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

class Solution {
public:
    int largestComponentSize(vector<int>& nums) {
        int max_val = *max_element(nums.begin(), nums.end());
        vector<int> parent(max_val + 1);
        for (int i = 0; i <= max_val; ++i) {
            parent[i] = i;
        }

        auto find = [&](auto& self, int i) -> int {
            if (parent[i] == i)
                return i;
            return parent[i] = self(self, parent[i]);
        };

        auto unite = [&](int i, int j) {
            int root_i = find(find, i);
            int root_j = find(find, j);
            if (root_i != root_j) {
                parent[root_i] = root_j;
            }
        };

        for (int x : nums) {
            for (int d = 2; d * d <= x; ++d) {
                if (x % d == 0) {
                    unite(x, d);
                    unite(x, x / d);
                }
            }
        }

        unordered_map<int, int> count;
        int max_size = 0;
        for (int x : nums) {
            int root = find(find, x);
            max_size = max(max_size, ++count[root]);
        }

        return max_size;
    }
};