// ──────────────────────────────────────────────────
// Problem  : 481. Magical String
// Difficulty: Medium
// Tags     : Two Pointers, String
// Link     : https://leetcode.com/problems/magical-string/
// Runtime  : 0 ms (beats 0%)
// Memory   : 7868000 (beats 0%)
// Language : cpp
// Copyright: (c) 2026 Srisakthi61. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

class Solution {
public:
    int magicalString(int n) {
        if (n <= 0) return 0;
        if (n <= 3) return 1;
        
        string s = "12211";
        s.resize(n);
        
        int head = 2;
        int tail = 4;
        int count = 1;
        
        while (tail < n) {
            int nextVal = (s[tail] == '1') ? '2' : '1';
            int len = s[head] - '0';
            
            for (int i = 0; i < len && tail < n; ++i) {
                s[++tail] = nextVal;
                if (nextVal == '1') {
                    count++;
                }
            }
            head++;
        }
        
        return count;
    }
};