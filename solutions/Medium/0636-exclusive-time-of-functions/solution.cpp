// ──────────────────────────────────────────────────
// Problem  : 636. Exclusive Time of Functions
// Difficulty: Medium
// Tags     : Array, Stack
// Link     : https://leetcode.com/problems/exclusive-time-of-functions/
// Runtime  : 6 ms (beats 49%)
// Memory   : 17008000 (beats 97%)
// Language : cpp
// Copyright: (c) 2026 Srisakthi61. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

class Solution {
public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        vector<int> res(n, 0);
        stack<int> st;
        int prevTime = 0;
        
        for (const string& log : logs) {
            int firstColon = log.find(':');
            int secondColon = log.rfind(':');
            
            int funcId = stoi(log.substr(0, firstColon));
            string type = log.substr(firstColon + 1, secondColon - firstColon - 1);
            int time = stoi(log.substr(secondColon + 1));
            
            if (type == "start") {
                if (!st.empty()) {
                    res[st.top()] += time - prevTime;
                }
                st.push(funcId);
                prevTime = time;
            } else {
                res[st.top()] += time - prevTime + 1;
                st.pop();
                prevTime = time + 1;
            }
        }
        
        return res;
    }
};