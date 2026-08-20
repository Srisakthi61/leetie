// ──────────────────────────────────────────────────
// Problem  : 289. Game of Life
// Difficulty: Medium
// Tags     : Array, Matrix, Simulation
// Link     : https://leetcode.com/problems/game-of-life/
// Runtime  : 0 ms (beats 100%)
// Memory   : 9716000 (beats 9%)
// Language : c
// Copyright: (c) 2026 Srisakthi61. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

void gameOfLife(int** board, int boardSize, int* boardColSize) {
    int m = boardSize;
    int n = boardColSize[0];

    int dirs[8][2] = {
        {-1, -1}, {-1, 0}, {-1, 1},
        { 0, -1},         { 0, 1},
        { 1, -1}, { 1, 0}, { 1, 1}
    };

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            int liveNeighbors = 0;

            for (int d = 0; d < 8; d++) {
                int ni = i + dirs[d][0];
                int nj = j + dirs[d][1];

                if (ni >= 0 && ni < m && nj >= 0 && nj < n) {
                    if (abs(board[ni][nj]) == 1) {
                        liveNeighbors++;
                    }
                }
            }

            if (board[i][j] == 1 && (liveNeighbors < 2 || liveNeighbors > 3)) {
                board[i][j] = -1;
            }
            if (board[i][j] == 0 && liveNeighbors == 3) {
                board[i][j] = 2;
            }
        }
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (board[i][j] > 0) {
                board[i][j] = 1;
            } else {
                board[i][j] = 0;
            }
        }
    }
}