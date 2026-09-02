// ──────────────────────────────────────────────────
// Problem  : 964. Least Operators to Express Number
// Difficulty: Hard
// Tags     : Math, Dynamic Programming, Memoization
// Link     : https://leetcode.com/problems/least-operators-to-express-number/
// Runtime  : 0 ms (beats 0%)
// Memory   : 7872000 (beats 0%)
// Language : cpp
// Copyright: (c) 2026 Srisakthi61. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

class Solution {
public:
    unordered_map<string, int> memo;
    int dp(int x, int target) {
        if (target == 0) return 0;
        if (target == x) return 0;
        if (target < x) {
            return min(target * 2 - 1, (x - target) * 2 + 1);
        }
        string key = to_string(x) + "," + to_string(target);
        if (memo.count(key)) return memo[key];

        long long sum = x;
        int k = 0;
        while (sum < target) {
            sum *= x;
            k++;
        }
        if (sum == target) return k;

        long long left = sum - target;
        long long right = target - (sum / x);

        int ans = k + dp(x, left);
        if (right < sum / x) {
            ans = min(ans, k - 1 + dp(x, right));
        }
        return memo[key] = ans;
    }

    int leastOpsExpressTarget(int x, int target) {
        memo.clear();
        return dp(x, target);
    }
};