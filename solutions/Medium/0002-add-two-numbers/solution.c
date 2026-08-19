// ──────────────────────────────────────────────────
// Problem  : 2. Add Two Numbers
// Difficulty: Medium
// Tags     : Linked List, Math, Recursion
// Link     : https://leetcode.com/problems/add-two-numbers/
// Runtime  : 0 ms (beats 100%)
// Memory   : 13424000 (beats 58%)
// Language : c
// Copyright: (c) 2026 Srisakthi61. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

#include <stdlib.h>

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
struct ListNode dummy;
dummy.next = NULL;
struct ListNode* curr = &dummy;

int carry = 0;

while (l1 != NULL || l2 != NULL || carry != 0) {
int sum = carry;

if (l1 != NULL) {
sum += l1->val;
l1 = l1->next;
}

if (l2 != NULL) {
sum += l2->val;
l2 = l2->next;
}

carry = sum / 10;

struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
newNode->val = sum % 10;
newNode->next = NULL;

curr->next = newNode;
curr = curr->next;
}

return dummy.next;
}