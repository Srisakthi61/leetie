// ──────────────────────────────────────────────────
// Problem  : 417. Pacific Atlantic Water Flow
// Difficulty: Medium
// Tags     : Array, Depth-First Search, Breadth-First Search, Matrix
// Link     : https://leetcode.com/problems/pacific-atlantic-water-flow/
// Runtime  : 4 ms (beats 77%)
// Memory   : 22224000 (beats 77%)
// Language : cpp
// Copyright: (c) 2026 Srisakthi61. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size();
        if (m == 0) return {};
        int n = heights[0].size();
        
        vector<vector<bool>> pacific(m, vector<bool>(n, false));
        vector<vector<bool>> atlantic(m, vector<bool>(n, false));
        
        for (int i = 0; i < m; ++i) {
            dfs(heights, pacific, i, 0);
            dfs(heights, atlantic, i, n - 1);
        }
        
        for (int j = 0; j < n; ++j) {
            dfs(heights, pacific, 0, j);
            dfs(heights, atlantic, m - 1, j);
        }
        
        vector<vector<int>> result;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (pacific[i][j] && atlantic[i][j]) {
                    result.push_back({i, j});
                }
            }
        }
        
        return result;
    }
    
private:
    void dfs(const vector<vector<int>>& heights, vector<vector<bool>>& visited, int i, int j) {
        visited[i][j] = true;
        int m = heights.size();
        int n = heights[0].size();
        
        int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        
        for (auto& dir : dirs) {
            int ni = i + dir[0];
            int nj = j + dir[1];
            
            if (ni >= 0 && ni < m && nj >= 0 && nj < n && !visited[ni][nj] && heights[ni][nj] >= heights[i][j]) {
                dfs(heights, visited, ni, nj);
            }
        }
    }
};