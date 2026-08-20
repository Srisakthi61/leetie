// ──────────────────────────────────────────────────
// Problem  : 284. Peeking Iterator
// Difficulty: Medium
// Tags     : Array, Design, Iterator
// Link     : https://leetcode.com/problems/peeking-iterator/
// Runtime  : 3 ms (beats 0%)
// Memory   : 8656000 (beats 0%)
// Language : c
// Copyright: (c) 2026 Srisakthi61. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

struct PeekingIterator {
    struct Iterator* iterator;
    bool hasNextVal;
    int nextVal;
};

struct PeekingIterator* Constructor(struct Iterator* iter) {
    struct PeekingIterator* piter = malloc(sizeof(struct PeekingIterator));
    piter->iterator = iter;
    piter->hasNextVal = iter->hasNext();
    if (piter->hasNextVal) {
        piter->nextVal = iter->next();
    }
    return piter;
}

int peek(struct PeekingIterator* obj) {
    return obj->nextVal;
}

int next(struct PeekingIterator* obj) {
    int res = obj->nextVal;
    obj->hasNextVal = obj->iterator->hasNext();
    if (obj->hasNextVal) {
        obj->nextVal = obj->iterator->next();
    }
    return res;
}

bool hasNext(struct PeekingIterator* obj) {
    return obj->hasNextVal;
}