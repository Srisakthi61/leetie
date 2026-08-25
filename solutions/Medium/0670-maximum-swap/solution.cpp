// ──────────────────────────────────────────────────
// Problem  : 670. Maximum Swap
// Difficulty: Medium
// Tags     : Math, Greedy
// Link     : https://leetcode.com/problems/maximum-swap/
// Runtime  : 0 ms (beats 0%)
// Memory   : 7804000 (beats 0%)
// Language : cpp
// Copyright: (c) 2026 Srisakthi61. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

class Solution {
public:
    int maximumSwap(int num) {
        string s = to_string(num);
        int n = s.length();
        vector<int> last(10, -1);
        for (int i = 0; i < n; ++i) {
            last[s[i] - '0'] = i;
        }
        for (int i = 0; i < n; ++i) {
            for (int d = 9; d > s[i] - '0'; --d) {
                if (last[d] > i) {
                    swap(s[i], s[last[d]]);
                    return stoi(s);
                }
            }
        }
        return num;
    }
};