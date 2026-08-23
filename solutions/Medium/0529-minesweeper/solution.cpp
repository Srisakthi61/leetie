// ──────────────────────────────────────────────────
// Problem  : 529. Minesweeper
// Difficulty: Medium
// Tags     : Array, Depth-First Search, Breadth-First Search, Matrix
// Link     : https://leetcode.com/problems/minesweeper/
// Runtime  : 0 ms (beats 0%)
// Memory   : 8720000 (beats 0%)
// Language : cpp
// Copyright: (c) 2026 Srisakthi61. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

class Solution {
public:
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        int r = click[0], c = click[1];
        
        if (board[r][c] == 'M') {
            board[r][c] = 'X';
            return board;
        }
        
        int m = board.size(), n = board[0].size();
        
        int mines = 0;
        for (int dr = -1; dr <= 1; dr++) {
            for (int dc = -1; dc <= 1; dc++) {
                if (dr == 0 && dc == 0) continue;
                int nr = r + dr, nc = c + dc;
                if (nr >= 0 && nr < m && nc >= 0 && nc < n && board[nr][nc] == 'M') {
                    mines++;
                }
            }
        }
        
        if (mines > 0) {
            board[r][c] = to_string(mines)[0];
        } else {
            board[r][c] = 'B';
            for (int dr = -1; dr <= 1; dr++) {
                for (int dc = -1; dc <= 1; dc++) {
                    if (dr == 0 && dc == 0) continue;
                    int nr = r + dr, nc = c + dc;
                    if (nr >= 0 && nr < m && nc >= 0 && nc < n && board[nr][nc] == 'E') {
                        vector<int> nextClick = {nr, nc};
                        updateBoard(board, nextClick);
                    }
                }
            }
        }
        
        return board;
    }
};