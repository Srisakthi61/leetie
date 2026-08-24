// ──────────────────────────────────────────────────
// Problem  : 638. Shopping Offers
// Difficulty: Medium
// Tags     : Array, Dynamic Programming, Backtracking, Bit Manipulation, Memoization, Bitmask, Knapsack Problem, Complete Knapsack
// Link     : https://leetcode.com/problems/shopping-offers/
// Runtime  : 0 ms (beats 0%)
// Memory   : 8544000 (beats 0%)
// Language : cpp
// Copyright: (c) 2026 Srisakthi61. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

class Solution {
public:
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        map<vector<int>, int> memo;
        return dfs(price, special, needs, memo);
    }

private:
    int dfs(const vector<int>& price, const vector<vector<int>>& special, vector<int>& needs, map<vector<int>, int>& memo) {
        if (memo.count(needs)) {
            return memo[needs];
        }

        int res = directPurchase(price, needs);

        for (const auto& s : special) {
            vector<int> nextNeeds = needs;
            bool isValid = true;
            for (int i = 0; i < needs.size(); ++i) {
                if (nextNeeds[i] < s[i]) {
                    isValid = false;
                    break;
                }
                nextNeeds[i] -= s[i];
            }

            if (isValid) {
                res = min(res, s.back() + dfs(price, special, nextNeeds, memo));
            }
        }

        return memo[needs] = res;
    }

    int directPurchase(const vector<int>& price, const vector<int>& needs) {
        int total = 0;
        for (int i = 0; i < price.size(); ++i) {
            total += price[i] * needs[i];
        }
        return total;
    }
};