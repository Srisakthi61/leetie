// ──────────────────────────────────────────────────
// Problem  : 407. Trapping Rain Water II
// Difficulty: Hard
// Tags     : Array, Breadth-First Search, Heap (Priority Queue), Matrix
// Link     : https://leetcode.com/problems/trapping-rain-water-ii/
// Runtime  : 25 ms (beats 76%)
// Memory   : 17396000 (beats 84%)
// Language : cpp
// Copyright: (c) 2026 Srisakthi61. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        if (heightMap.empty() || heightMap[0].empty()) return 0;
        
        int m = heightMap.size();
        int n = heightMap[0].size();
        
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i == 0 || i == m - 1 || j == 0 || j == n - 1) {
                    pq.push({heightMap[i][j], {i, j}});
                    visited[i][j] = true;
                }
            }
        }
        
        int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        int waterTrapped = 0;
        int maxBoundaryHeight = 0;
        
        while (!pq.empty()) {
            auto cell = pq.top();
            pq.pop();
            
            int h = cell.first;
            int r = cell.second.first;
            int c = cell.second.second;
            
            maxBoundaryHeight = max(maxBoundaryHeight, h);
            
            for (auto& dir : dirs) {
                int nr = r + dir[0];
                int nc = c + dir[1];
                
                if (nr >= 0 && nr < m && nc >= 0 && nc < n && !visited[nr][nc]) {
                    visited[nr][nc] = true;
                    
                    if (heightMap[nr][nc] < maxBoundaryHeight) {
                        waterTrapped += maxBoundaryHeight - heightMap[nr][nc];
                    }
                    
                    pq.push({heightMap[nr][nc], {nr, nc}});
                }
            }
        }
        
        return waterTrapped;
    }
};