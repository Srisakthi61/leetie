// ──────────────────────────────────────────────────
// Problem  : 466. Count The Repetitions
// Difficulty: Hard
// Tags     : Two Pointers, String, Dynamic Programming
// Link     : https://leetcode.com/problems/count-the-repetitions/
// Runtime  : 0 ms (beats 0%)
// Memory   : 7864000 (beats 0%)
// Language : cpp
// Copyright: (c) 2026 Srisakthi61. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

class Solution {
public:
    int getMaxRepetitions(string s1, int n1, string s2, int n2) {
        vector<int> repeatCount(n1 + 1, 0);
        vector<int> nextIndex(n1 + 1, 0);
        int j = 0, count = 0;
        
        for (int k = 1; k <= n1; ++k) {
            for (int i = 0; i < s1.size(); ++i) {
                if (s1[i] == s2[j]) {
                    j++;
                    if (j == s2.size()) {
                        j = 0;
                        count++;
                    }
                }
            }
            repeatCount[k] = count;
            nextIndex[k] = j;
            
            for (int start = 0; start < k; ++start) {
                if (nextIndex[start] == j) {
                    int prevCount = repeatCount[start];
                    int periodCount = (n1 - start) / (k - start) * (count - prevCount);
                    int remCount = repeatCount[start + (n1 - start) % (k - start)] - prevCount;
                    return (prevCount + periodCount + remCount) / n2;
                }
            }
        }
        
        return repeatCount[n1] / n2;
    }
};
