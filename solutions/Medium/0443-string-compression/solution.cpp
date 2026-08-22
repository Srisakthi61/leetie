// ──────────────────────────────────────────────────
// Problem  : 443. String Compression
// Difficulty: Medium
// Tags     : Two Pointers, String
// Link     : https://leetcode.com/problems/string-compression/
// Runtime  : 0 ms (beats 0%)
// Memory   : 8320000 (beats 0%)
// Language : cpp
// Copyright: (c) 2026 Srisakthi61. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size();
        int write = 0;
        int read = 0;
        
        while (read < n) {
            char currChar = chars[read];
            int start = read;
            
            while (read < n && chars[read] == currChar) {
                read++;
            }
            
            int count = read - start;
            chars[write++] = currChar;
            
            if (count > 1) {
                string countStr = to_string(count);
                for (char c : countStr) {
                    chars[write++] = c;
                }
            }
        }
        
        return write;
    }
};