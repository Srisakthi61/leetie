// ──────────────────────────────────────────────────
// Problem  : 473. Matchsticks to Square
// Difficulty: Medium
// Tags     : Array, Dynamic Programming, Backtracking, Bit Manipulation, Bitmask
// Link     : https://leetcode.com/problems/matchsticks-to-square/
// Runtime  : 11 ms (beats 75%)
// Memory   : 12876000 (beats 47%)
// Language : cpp
// Copyright: (c) 2026 Srisakthi61. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

class Solution {
public:
    bool makesquare(vector<int>& matchsticks) {
        long long sum = 0;
        for (int len : matchsticks) {
            sum += len;
        }
        
        if (sum % 4 != 0) return false;
        long long target = sum / 4;
        
        sort(matchsticks.rbegin(), matchsticks.rend());
        if (matchsticks[0] > target) return false;
        
        vector<int> sides(4, 0);
        return backtrack(matchsticks, 0, target, sides);
    }
    
private:
    bool backtrack(const vector<int>& matchsticks, int index, long long target, vector<int>& sides) {
        if (index == matchsticks.size()) {
            return sides[0] == target && sides[1] == target && sides[2] == target && sides[3] == target;
        }
        
        int match = matchsticks[index];
        for (int i = 0; i < 4; i++) {
            if (sides[i] + match <= target) {
                sides[i] += match;
                if (backtrack(matchsticks, index + 1, target, sides)) return true;
                sides[i] -= match;
            }
            if (sides[i] == 0) break;
        }
        
        return false;
    }
};