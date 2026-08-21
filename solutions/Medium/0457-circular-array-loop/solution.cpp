// ──────────────────────────────────────────────────
// Problem  : 457. Circular Array Loop
// Difficulty: Medium
// Tags     : Array, Hash Table, Two Pointers, Floyd's Cycle Finding Algorithm
// Link     : https://leetcode.com/problems/circular-array-loop/
// Runtime  : 0 ms (beats 0%)
// Memory   : 8148000 (beats 0%)
// Language : cpp
// Copyright: (c) 2026 Srisakthi61. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

class Solution {
public:
    bool circularArrayLoop(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            if (nums[i] == 0) continue;
            
            int slow = i, fast = i;
            bool is_forward = nums[i] > 0;
            
            while (true) {
                slow = getNext(nums, slow, is_forward);
                if (slow == -1) break;
                
                fast = getNext(nums, fast, is_forward);
                if (fast == -1) break;
                
                fast = getNext(nums, fast, is_forward);
                if (fast == -1) break;
                
                if (slow == fast) return true;
            }
            
            int curr = i;
            while (nums[curr] != 0 && (nums[curr] > 0) == is_forward) {
                int next = getNext(nums, curr, is_forward);
                nums[curr] = 0;
                if (next == -1) break;
                curr = next;
            }
        }
        return false;
    }

private:
    int getNext(const vector<int>& nums, int i, bool is_forward) {
        bool dir = nums[i] > 0;
        if (dir != is_forward) return -1;
        
        int n = nums.size();
        int next = (i + nums[i]) % n;
        if (next < 0) next += n;
        
        if (next == i) return -1;
        
        return next;
    }
};