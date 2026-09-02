// ──────────────────────────────────────────────────
// Problem  : 972. Equal Rational Numbers
// Difficulty: Hard
// Tags     : Math, String
// Link     : https://leetcode.com/problems/equal-rational-numbers/
// Runtime  : 0 ms (beats 0%)
// Memory   : 7644000 (beats 0%)
// Language : cpp
// Copyright: (c) 2026 Srisakthi61. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

class Solution {
private:
    long long convert(string s) {
        int i = s.find('.');
        if (i == string::npos) {
            return stol(s) * 1000000000L;
        }
        long long int_part = stol(s.substr(0, i));
        long long res = int_part * 1000000000L;
        string non_rep = "";
        string rep = "";
        int j = s.find('(', i);
        if (j == string::npos) {
            non_rep = s.substr(i + 1);
            while (non_rep.length() < 9) {
                non_rep += "0";
            }
            res += stol(non_rep.substr(0, 9));
        } else {
            non_rep = s.substr(i + 1, j - i - 1);
            rep = s.substr(j + 1, s.length() - j - 2);
            string temp = non_rep;
            while (temp.length() < 9) {
                temp += rep;
            }
            res += stol(temp.substr(0, 9));
        }
        return res;
    }

public:
    bool isRationalEqual(string s, string t) {
        long long val1 = convert(s);
        long long val2 = convert(t);
        if (val1 == val2) return true;
        
        string s9 = s;
        if (s.find('(') == string::npos) {
            if (s.find('.') == string::npos) {
                s9 = s + ".$(9)";
            } else {
                s9 = s + "(9)";
            }
        }
        
        string t9 = t;
        if (t.find('(') == string::npos) {
            if (t.find('.') == string::npos) {
                t9 = t + ".(9)";
            } else {
                t9 = t + "(9)";
            }
        }
        
        return convert(s9) == convert(t9) || val1 == convert(t9) || convert(s9) == val2;
    }
};