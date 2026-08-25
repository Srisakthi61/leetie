// ──────────────────────────────────────────────────
// Problem  : 382. Linked List Random Node
// Difficulty: Medium
// Tags     : Linked List, Math, Reservoir Sampling, Randomized
// Link     : https://leetcode.com/problems/linked-list-random-node/
// Runtime  : 0 ms (beats 0%)
// Memory   : 8772000 (beats 0%)
// Language : cpp
// Copyright: (c) 2026 Srisakthi61. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

class Solution {
    ListNode* headNode;
public:
    Solution(ListNode* head) {
        headNode = head;
        srand(time(nullptr));
    }
    
    int getRandom() {
        int res = headNode->val;
        ListNode* curr = headNode->next;
        int i = 2;
        while (curr != nullptr) {
            if (rand() % i == 0) {
                res = curr->val;
            }
            curr = curr->next;
            i++;
        }
        return res;
    }
};