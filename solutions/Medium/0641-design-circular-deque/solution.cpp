// ──────────────────────────────────────────────────
// Problem  : 641. Design Circular Deque
// Difficulty: Medium
// Tags     : Array, Linked List, Design, Queue
// Link     : https://leetcode.com/problems/design-circular-deque/
// Runtime  : 0 ms (beats 100%)
// Memory   : 24460000 (beats 78%)
// Language : cpp
// Copyright: (c) 2026 Srisakthi61. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

class MyCircularDeque {
private:
    vector<int> q;
    int frontIdx;
    int rearIdx;
    int size;
    int capacity;

public:
    MyCircularDeque(int k) {
        capacity = k;
        q.resize(k);
        frontIdx = 0;
        rearIdx = k - 1;
        size = 0;
    }
    
    bool insertFront(int value) {
        if (isFull()) {
            return false;
        }
        frontIdx = (frontIdx - 1 + capacity) % capacity;
        q[frontIdx] = value;
        size++;
        return true;
    }
    
    bool insertLast(int value) {
        if (isFull()) {
            return false;
        }
        rearIdx = (rearIdx + 1) % capacity;
        q[rearIdx] = value;
        size++;
        return true;
    }
    
    bool deleteFront() {
        if (isEmpty()) {
            return false;
        }
        frontIdx = (frontIdx + 1) % capacity;
        size--;
        return true;
    }
    
    bool deleteLast() {
        if (isEmpty()) {
            return false;
        }
        rearIdx = (rearIdx - 1 + capacity) % capacity;
        size--;
        return true;
    }
    
    int getFront() {
        if (isEmpty()) {
            return -1;
        }
        return q[frontIdx];
    }
    
    int getRear() {
        if (isEmpty()) {
            return -1;
        }
        return q[rearIdx];
    }
    
    bool isEmpty() {
        return size == 0;
    }
    
    bool isFull() {
        return size == capacity;
    }
};