// ──────────────────────────────────────────────────
// Problem  : 149. Max Points on a Line
// Difficulty: Hard
// Tags     : Array, Hash Table, Math, Geometry, Euclidean Algorithm, Greatest Common Divisor
// Link     : https://leetcode.com/problems/max-points-on-a-line/
// Runtime  : 17 ms (beats 30%)
// Memory   : 9496000 (beats 90%)
// Language : c
// Copyright: (c) 2026 Srisakthi61. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

int maxPoints(int** points, int pointsSize, int* pointsColSize) {
if (pointsSize <= 2) return pointsSize;
int max_pts = 0;

for (int i = 0; i < pointsSize; i++) {
for (int j = i + 1; j < pointsSize; j++) {
int count = 2;
long long dx = points[j][0] - points[i][0];
long long dy = points[j][1] - points[i][1];

for (int k = j + 1; k < pointsSize; k++) {
long long dx2 = points[k][0] - points[i][0];
long long dy2 = points[k][1] - points[i][1];

if (dy * dx2 == dx * dy2) {
count++;
}
}

if (count > max_pts) {
max_pts = count;
}
}
}

return max_pts;
}
