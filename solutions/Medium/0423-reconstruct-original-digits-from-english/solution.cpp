// ──────────────────────────────────────────────────
// Problem  : 423. Reconstruct Original Digits from English
// Difficulty: Medium
// Tags     : Hash Table, Math, String
// Link     : https://leetcode.com/problems/reconstruct-original-digits-from-english/
// Runtime  : 0 ms (beats 100%)
// Memory   : 12120000 (beats 53%)
// Language : cpp
// Copyright: (c) 2026 Srisakthi61. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

class Solution {
public:
    string originalDigits(string s) {
        vector<int> count(26, 0);
        for (char c : s) {
            count[c - 'a']++;
        }
        
        vector<int> out(10, 0);
        out[0] = count['z' - 'a'];
        out[2] = count['w' - 'a'];
        out[4] = count['u' - 'a'];
        out[6] = count['x' - 'a'];
        out[8] = count['g' - 'a'];
        
        out[3] = count['h' - 'a'] - out[8];
        out[5] = count['f' - 'a'] - out[4];
        out[7] = count['s' - 'a'] - out[6];
        
        out[1] = count['o' - 'a'] - out[0] - out[2] - out[4];
        out[9] = count['i' - 'a'] - out[5] - out[6] - out[8];
        
        string res = "";
        for (int i = 0; i <= 9; i++) {
            res.append(out[i], '0' + i);
        }
        return res;
    }
};