// ──────────────────────────────────────────────────
// Problem  : 866. Prime Palindrome
// Difficulty: Medium
// Tags     : Math, Number Theory, Primality Test
// Link     : https://leetcode.com/problems/prime-palindrome/
// Runtime  : 0 ms (beats 0%)
// Memory   : 8120000 (beats 0%)
// Language : cpp
// Copyright: (c) 2026 Srisakthi61. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

class Solution {
public:
    int primePalindrome(int n) {
        if (n >= 8 && n <= 11) {
            return 11;
        }
        for (int length = 1; length <= 9; ++length) {
            int low = pow(10, (length - 1) / 2);
            int high = pow(10, (length + 1) / 2);
            for (int i = low; i < high; ++i) {
                string s = to_string(i);
                string r = s;
                reverse(r.begin(), r.end());
                string candidate = s + r.substr(length % 2);
                int val = stoi(candidate);
                if (val >= n && isPrime(val)) {
                    return val;
                }
            }
        }
        return -1;
    }

private:
    bool isPrime(int num) {
        if (num < 2) return false;
        if (num == 2 || num == 3) return true;
        if (num % 2 == 0 || num % 3 == 0) return false;
        for (int i = 5; i * i <= num; i += 6) {
            if (num % i == 0 || num % (i + 2) == 0) return false;
        }
        return true;
    }
};