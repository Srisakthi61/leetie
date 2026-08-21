// ──────────────────────────────────────────────────
// Problem  : 399. Evaluate Division
// Difficulty: Medium
// Tags     : Array, String, Depth-First Search, Breadth-First Search, Union-Find, Graph Theory, Shortest Path, Bellman–Ford Algorithm, Floyd–Warshall Algorithm
// Link     : https://leetcode.com/problems/evaluate-division/
// Runtime  : 0 ms (beats 100%)
// Memory   : 11576000 (beats 97%)
// Language : cpp
// Copyright: (c) 2026 Srisakthi61. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string, unordered_map<string, double>> graph;
        
        for (int i = 0; i < equations.size(); ++i) {
            string u = equations[i][0];
            string v = equations[i][1];
            double w = values[i];
            graph[u][v] = w;
            graph[v][u] = 1.0 / w;
        }
        
        vector<double> res;
        
        for (const auto& q : queries) {
            string src = q[0];
            string dst = q[1];
            
            if (graph.find(src) == graph.end() || graph.find(dst) == graph.end()) {
                res.push_back(-1.0);
            } else {
                unordered_set<string> visited;
                double ans = -1.0;
                dfs(src, dst, graph, visited, 1.0, ans);
                res.push_back(ans);
            }
        }
        
        return res;
    }

private:
    void dfs(const string& curr, const string& dst, 
             unordered_map<string, unordered_map<string, double>>& graph, 
             unordered_set<string>& visited, double current_product, double& ans) {
        
        if (curr == dst) {
            ans = current_product;
            return;
        }
        
        visited.insert(curr);
        
        for (const auto& neighbor : graph[curr]) {
            if (visited.find(neighbor.first) == visited.end()) {
                dfs(neighbor.first, dst, graph, visited, current_product * neighbor.second, ans);
                if (ans != -1.0) {
                    return;
                }
            }
        }
    }
};