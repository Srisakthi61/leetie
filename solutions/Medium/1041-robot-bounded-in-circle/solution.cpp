// ──────────────────────────────────────────────────
// Problem  : 1041. Robot Bounded In Circle
// Difficulty: Medium
// Tags     : Math, String, Simulation
// Link     : https://leetcode.com/problems/robot-bounded-in-circle/
// Runtime  : 0 ms (beats 0%)
// Memory   : 7748000 (beats 0%)
// Language : cpp
// Copyright: (c) 2026 Srisakthi61. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

class Solution {
public:
    bool isRobotBounded(string instructions) {
        int x = 0, y = 0;
        int dx = 0, dy = 1; // Initially facing North (0, 1)
        
        for (char c : instructions) {
            if (c == 'G') {
                x += dx;
                y += dy;
            } else if (c == 'L') {
                int temp = dx;
                dx = -dy;
                dy = temp;
            } else if (c == 'R') {
                int temp = dx;
                dx = dy;
                dy = -temp;
            }
        }
        
        return (x == 0 && y == 0) || (dx != 0 || dy != 1);
    }
};