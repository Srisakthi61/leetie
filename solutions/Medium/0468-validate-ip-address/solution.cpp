// ──────────────────────────────────────────────────
// Problem  : 468. Validate IP Address
// Difficulty: Medium
// Tags     : String
// Link     : https://leetcode.com/problems/validate-ip-address/
// Runtime  : 0 ms (beats 0%)
// Memory   : 7868000 (beats 0%)
// Language : cpp
// Copyright: (c) 2026 Srisakthi61. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

class Solution {
public:
    string validIPAddress(string queryIP) {
        if (isValidIPv4(queryIP)) return "IPv4";
        if (isValidIPv6(queryIP)) return "IPv6";
        return "Neither";
    }

private:
    bool isValidIPv4(string s) {
        int count = 0;
        for (char c : s) {
            if (c == '.') count++;
        }
        if (count != 3) return false;

        stringstream ss(s);
        string token;
        int parts = 0;
        while (getline(ss, token, '.')) {
            parts++;
            if (parts > 4 || token.empty() || token.length() > 3) return false;
            if (token[0] == '0' && token.length() > 1) return false;
            int num = 0;
            for (char c : token) {
                if (!isdigit(c)) return false;
                num = num * 10 + (c - '0');
            }
            if (num > 255) return false;
        }
        return parts == 4 && s.back() != '.';
    }

    bool isValidIPv6(string s) {
        int count = 0;
        for (char c : s) {
            if (c == ':') count++;
        }
        if (count != 7) return false;

        stringstream ss(s);
        string token;
        int parts = 0;
        while (getline(ss, token, ':')) {
            parts++;
            if (parts > 8 || token.empty() || token.length() > 4) return false;
            for (char c : token) {
                if (!isxdigit(c) || isupper(c) && c > 'F' || islower(c) && c > 'f') {
                    // Check valid hex
                    if (!((c >= '0' && c <= '9') || (c >= 'a' && c <= 'f') || (c >= 'A' && c <= 'F'))) {
                        return false;
                    }
                }
            }
        }
        return parts == 8 && s.back() != ':';
    }
};