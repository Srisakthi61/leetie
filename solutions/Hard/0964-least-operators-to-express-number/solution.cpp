// ──────────────────────────────────────────────────
// Problem  : 964. Least Operators to Express Number
// Difficulty: Hard
// Tags     : Math, Dynamic Programming, Memoization
// Link     : https://leetcode.com/problems/least-operators-to-express-number/
// Runtime  : 0 ms (beats 0%)
// Memory   : 7984000 (beats 0%)
// Language : cpp
// Copyright: (c) 2026 Srisakthi61. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

class Solution {
public:
    unordered_map<long long, int> memo;
    int dp(long long x, long long target) {
        if (target == 0) return 0;
        if (target == x) return 1;
        if (target < x) {
            return min((int)target * 2 - 1, (int)(x - target) * 2 + 1);
        }
        if (memo.count(target)) return memo[target];

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
        return memo[target] = ans;
    }

    int leastOpsExpressTarget(int x, int target) {
        memo.clear();
        return dp(x, target);
    }
};