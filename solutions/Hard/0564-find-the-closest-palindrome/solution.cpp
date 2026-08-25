// ──────────────────────────────────────────────────
// Problem  : 564. Find the Closest Palindrome
// Difficulty: Hard
// Tags     : Math, String
// Link     : https://leetcode.com/problems/find-the-closest-palindrome/
// Runtime  : 0 ms (beats 0%)
// Memory   : 8140000 (beats 0%)
// Language : cpp
// Copyright: (c) 2026 Srisakthi61. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

class Solution {
public:
    string nearestPalindromic(string n) {
        long long len = n.length();
        long long num = stoll(n);
        vector<long long> candidates;
        
        candidates.push_back(pow(10, len - 1) - 1);
        candidates.push_back(pow(10, len) + 1);
        
        long long mid = (len + 1) / 2;
        long long prefix = stoll(n.substr(0, mid));
        
        for (long long i = -1; i <= 1; ++i) {
            string p = to_string(prefix + i);
            string rev = p;
            if (len % 2 != 0) {
                rev.pop_back();
            }
            reverse(rev.begin(), rev.end());
            candidates.push_back(stoll(p + rev));
        }
        
        long long ans = -1;
        for (long long cand : candidates) {
            if (cand == num) continue;
            if (ans == -1 || abs(cand - num) < abs(ans - num) || 
                (abs(cand - num) == abs(ans - num) && cand < ans)) {
                ans = cand;
            }
        }
        
        return to_string(ans);
    }
};