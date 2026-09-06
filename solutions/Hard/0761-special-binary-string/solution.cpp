// ──────────────────────────────────────────────────
// Problem  : 761. Special Binary String
// Difficulty: Hard
// Tags     : String, Divide and Conquer, Sorting
// Link     : https://leetcode.com/problems/special-binary-string/
// Runtime  : 0 ms (beats 0%)
// Memory   : 7908000 (beats 0%)
// Language : cpp
// Copyright: (c) 2026 Srisakthi61. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

class Solution {
public:
    string makeLargestSpecial(string s) {
        int count = 0, i = 0;
        vector<string> res;
        for (int j = 0; j < s.size(); ++j) {
            if (s[j] == '1') count++;
            else count--;
            if (count == 0) {
                res.push_back('1' + makeLargestSpecial(s.substr(i + 1, j - i - 1)) + '0');
                i = j + 1;
            }
        }
        sort(res.begin(), res.end(), greater<string>());
        string ans = "";
        for (string str : res) {
            ans += str;
        }
        return ans;
    }
};