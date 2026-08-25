// ──────────────────────────────────────────────────
// Problem  : 445. Add Two Numbers II
// Difficulty: Medium
// Tags     : Linked List, Math, Stack
// Link     : https://leetcode.com/problems/add-two-numbers-ii/
// Runtime  : 2 ms (beats 54%)
// Memory   : 79552000 (beats 8%)
// Language : cpp
// Copyright: (c) 2026 Srisakthi61. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int> s1, s2;
        while (l1 != nullptr) {
            s1.push(l1->val);
            l1 = l1->next;
        }
        while (l2 != nullptr) {
            s2.push(l2->val);
            l2 = l2->next;
        }

        int carry = 0;
        ListNode* head = nullptr;
        while (!s1.empty() || !s2.empty() || carry != 0) {
            int sum = carry;
            if (!s1.empty()) {
                sum += s1.top();
                s1.pop();
            }
            if (!s2.empty()) {
                sum += s2.top();
                s2.pop();
            }
            carry = sum / 10;
            ListNode* newNode = new ListNode(sum % 10);
            newNode->next = head;
            head = newNode;
        }
        return head;
    }
};