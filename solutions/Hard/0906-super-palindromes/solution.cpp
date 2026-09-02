// ──────────────────────────────────────────────────
// Problem  : 906. Super Palindromes
// Difficulty: Hard
// Tags     : Math, String, Enumeration
// Link     : https://leetcode.com/problems/super-palindromes/
// Runtime  : 137 ms (beats 52%)
// Memory   : 10292000 (beats 59%)
// Language : cpp
// Copyright: (c) 2026 Srisakthi61. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

class Solution {
public:
    int superpalindromesInRange(string left, string right) {
        long long l = stoll(left);
        long long r = stoll(right);
        int count = 0;

        auto isPalindrome = [](long long n) {
            long long temp = n;
            long long rev = 0;
            while (temp > 0) {
                rev = rev * 10 + temp % 10;
                temp /= 10;
            }
            return n == rev;
        };

        for (long long i = 1; i < 100000; ++i) {
            string s = to_string(i);
            string rev_s = s;
            reverse(rev_s.begin(), rev_s.end());
            
            string p1 = s + rev_s.substr(1);
            long long v1 = stoll(p1);
            if (v1 <= 3037000000LL) {
                long long sq1 = v1 * v1;
                if (sq1 > r) break;
                if (sq1 >= l && isPalindrome(sq1)) {
                    count++;
                }
            }

            string p2 = s + rev_s;
            long long v2 = stoll(p2);
            if (v2 <= 3037000000LL) {
                long long sq2 = v2 * v2;
                if (sq2 >= l && sq2 <= r && isPalindrome(sq2)) {
                    count++;
                }
            }
        }

        return count;
    }
};