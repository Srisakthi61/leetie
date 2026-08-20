// ──────────────────────────────────────────────────
// Problem  : 220. Contains Duplicate III
// Difficulty: Hard
// Tags     : Array, Sliding Window, Sorting, Bucket Sort, Ordered Set
// Link     : https://leetcode.com/problems/contains-duplicate-iii/
// Runtime  : 0 ms (beats 0%)
// Memory   : 8472000 (beats 0%)
// Language : c
// Copyright: (c) 2026 Srisakthi61. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

#include <stdbool.h>
#include <stdlib.h>

// Hash map node for bucket sort strategy
typedef struct Node {
    long key;
    long val;
    struct Node* next;
} Node;

#define HASH_SIZE 10007

int hash(long key) {
    int h = key % HASH_SIZE;
    return h < 0 ? h + HASH_SIZE : h;
}

void insert(Node** hashTable, long key, long val) {
    int idx = hash(key);
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->key = key;
    newNode->val = val;
    newNode->next = hashTable[idx];
    hashTable[idx] = newNode;
}

bool find(Node** hashTable, long key, long* val) {
    int idx = hash(key);
    Node* curr = hashTable[idx];
    while (curr) {
        if (curr->key == key) {
            *val = curr->val;
            return true;
        }
        curr = curr->next;
    }
    return false;
}

void erase(Node** hashTable, long key) {
    int idx = hash(key);
    Node* curr = hashTable[idx];
    Node* prev = NULL;
    while (curr) {
        if (curr->key == key) {
            if (prev) {
                prev->next = curr->next;
            } else {
                hashTable[idx] = curr->next;
            }
            free(curr);
            return;
        }
        prev = curr;
        curr = curr->next;
    }
}

long getBucketId(long val, long w) {
    return val < 0 ? (val + 1) / w - 1 : val / w;
}

bool containsNearbyAlmostDuplicate(int* nums, int numsSize, int indexDiff, int valueDiff) {
    if (numsSize < 2 || indexDiff <= 0 || valueDiff < 0) {
        return false;
    }

    Node* hashTable[HASH_SIZE] = {NULL};
    long w = (long)valueDiff + 1;

    for (int i = 0; i < numsSize; i++) {
        long val = nums[i];
        long bucket = getBucketId(val, w);

        long dummy;
        // Check if the current bucket already contains an element
        if (find(hashTable, bucket, &dummy)) {
            // Free memory before returning
            for (int j = 0; j < HASH_SIZE; j++) {
                Node* curr = hashTable[j];
                while (curr) { Node* tmp = curr; curr = curr->next; free(tmp); }
            }
            return true;
        }

        // Check neighboring buckets
        long neighborVal;
        if (find(hashTable, bucket - 1, &neighborVal) && val - neighborVal <= valueDiff) {
            for (int j = 0; j < HASH_SIZE; j++) {
                Node* curr = hashTable[j];
                while (curr) { Node* tmp = curr; curr = curr->next; free(tmp); }
            }
            return true;
        }
        if (find(hashTable, bucket + 1, &neighborVal) && neighborVal - val <= valueDiff) {
            for (int j = 0; j < HASH_SIZE; j++) {
                Node* curr = hashTable[j];
                while (curr) { Node* tmp = curr; curr = curr->next; free(tmp); }
            }
            return true;
        }

        // Add current element to the bucket map
        insert(hashTable, bucket, val);

        // Remove elements outside the index window
        if (i >= indexDiff) {
            long oldBucket = getBucketId(nums[i - indexDiff], w);
            erase(hashTable, oldBucket);
        }
    }

    // Clean up allocated memory
    for (int j = 0; j < HASH_SIZE; j++) {
        Node* curr = hashTable[j];
        while (curr) {
            Node* tmp = curr;
            curr = curr->next;
            free(tmp);
        }
    }

    return false;
}