// ──────────────────────────────────────────────────
// Problem  : 913. Cat and Mouse
// Difficulty: Hard
// Tags     : Math, Dynamic Programming, Graph Theory, Topological Sort, Memoization, Minimax, Game Theory, Zero-Sum Game
// Link     : https://leetcode.com/problems/cat-and-mouse/
// Runtime  : 52 ms (beats 60%)
// Memory   : 26124000 (beats 69%)
// Language : cpp
// Copyright: (c) 2026 Srisakthi61. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

class Solution {
public:
    int catMouseGame(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<vector<int>>> color(n, vector<vector<int>>(n, vector<int>(3, 0)));
        vector<vector<vector<int>>> degree(n, vector<vector<int>>(n, vector<int>(3, 0)));
        queue<tuple<int, int, int>> q;

        for (int m = 0; m < n; ++m) {
            for (int c = 1; c < n; ++c) {
                degree[m][c][1] = graph[m].size();
                degree[m][c][2] = graph[c].size();
                for (int node : graph[c]) {
                    if (node == 0) {
                        degree[m][c][2]--;
                        break;
                    }
                }
            }
        }

        for (int c = 1; c < n; ++c) {
            for (int t = 1; t <= 2; ++t) {
                color[0][c][t] = 1;
                q.push({0, c, t});
                color[c][c][t] = 2;
                q.push({c, c, t});
            }
        }

        while (!q.empty()) {
            auto [m, c, t] = q.front();
            q.pop();
            int cl = color[m][c][t];

            if (t == 1) {
                for (int prev_c : graph[c]) {
                    if (prev_c == 0) continue;
                    if (color[m][prev_c][2] == 0) {
                        if (cl == 2) {
                            color[m][prev_c][2] = 2;
                            q.push({m, prev_c, 2});
                        } else {
                            degree[m][prev_c][2]--;
                            if (degree[m][prev_c][2] == 0) {
                                color[m][prev_c][2] = 1;
                                q.push({m, prev_c, 2});
                            }
                        }
                    }
                }
            } else {
                for (int prev_m : graph[m]) {
                    if (color[prev_m][c][1] == 0) {
                        if (cl == 1) {
                            color[prev_m][c][1] = 1;
                            q.push({prev_m, c, 1});
                        } else {
                            degree[prev_m][c][1]--;
                            if (degree[prev_m][c][1] == 0) {
                                color[prev_m][c][1] = 2;
                                q.push({prev_m, c, 1});
                            }
                        }
                    }
                }
            }
        }

        return color[1][2][1];
    }
};