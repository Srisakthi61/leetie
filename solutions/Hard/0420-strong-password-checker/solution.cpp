// ──────────────────────────────────────────────────
// Problem  : 420. Strong Password Checker
// Difficulty: Hard
// Tags     : String, Greedy, Heap (Priority Queue)
// Link     : https://leetcode.com/problems/strong-password-checker/
// Runtime  : 0 ms (beats 0%)
// Memory   : 7568000 (beats 0%)
// Language : cpp
// Copyright: (c) 2026 Srisakthi61. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

class Solution {
public:
    int strongPasswordChecker(string password) {
        int n = password.length();
        bool hasLower = false, hasUpper = false, hasDigit = false;

        for (char c : password) {
            if (islower(c)) hasLower = true;
            else if (isupper(c)) hasUpper = true;
            else if (isdigit(c)) hasDigit = true;
        }

        int missingTypes = (hasLower ? 0 : 1) + (hasUpper ? 0 : 1) + (hasDigit ? 0 : 1);

        if (n < 6) {
            return max(missingTypes, 6 - n);
        }

        if (n <= 20) {
            int replace = 0;
            int i = 0;
            while (i < n) {
                int length = 1;
                while (i + length < n && password[i + length] == password[i]) {
                    length++;
                }
                if (length >= 3) {
                    replace += length / 3;
                }
                i += length;
            }
            return max(missingTypes, replace);
        }

        int deleteCount = n - 20;
        int replace = 0;
        int overLen = n - 20;
        vector<int> l1, l2;
        
        int i = 0;
        while (i < n) {
            int length = 1;
            while (i + length < n && password[i + length] == password[i]) {
                length++;
            }
            if (length >= 3) {
                replace += length / 3;
                if (length % 3 == 0) l1.push_back(length);
                else if (length % 3 == 1) l2.push_back(length);
            }
            i += length;
        }

        for (int len : l1) {
            if (overLen > 0 && len >= 3) {
                int reduce = min(overLen, 1);
                overLen -= reduce;
                replace -= reduce;
            }
        }
        for (int len : l2) {
            if (overLen > 1 && len >= 5) {
                int reduce = min(overLen, 2);
                overLen -= reduce;
                replace -= reduce / 2;
            }
        }
        for (int i = 0; i < n; ) {
            int length = 1;
            while (i + length < n && password[i + length] == password[i]) {
                length++;
            }
            if (length >= 3 && length % 3 == 2) {
                if (overLen > 2) {
                    int reduce = min(overLen, 3);
                    overLen -= reduce;
                    replace -= reduce / 3;
                }
            }
            i += length;
        }

        return deleteCount + max(missingTypes, replace);
    }
};