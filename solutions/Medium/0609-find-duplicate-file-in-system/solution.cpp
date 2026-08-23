// ──────────────────────────────────────────────────
// Problem  : 609. Find Duplicate File in System
// Difficulty: Medium
// Tags     : Array, Hash Table, String
// Link     : https://leetcode.com/problems/find-duplicate-file-in-system/
// Runtime  : 31 ms (beats 98%)
// Memory   : 39616000 (beats 77%)
// Language : cpp
// Copyright: (c) 2026 Srisakthi61. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

class Solution {
public:
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        unordered_map<string, vector<string>> contentMap;
        
        for (const string& pathInfo : paths) {
            stringstream ss(pathInfo);
            string dir;
            ss >> dir;
            
            string fileInfo;
            while (ss >> fileInfo) {
                size_t idx = fileInfo.find('(');
                string fileName = fileInfo.substr(0, idx);
                string content = fileInfo.substr(idx + 1, fileInfo.length() - idx - 2);
                
                contentMap[content].push_back(dir + "/" + fileName);
            }
        }
        
        vector<vector<string>> result;
        for (auto& entry : contentMap) {
            if (entry.second.size() > 1) {
                result.push_back(entry.second);
            }
        }
        
        return result;
    }
};