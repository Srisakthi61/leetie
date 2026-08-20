// ──────────────────────────────────────────────────
// Problem  : 380. Insert Delete GetRandom O(1)
// Difficulty: Medium
// Tags     : Array, Hash Table, Math, Design, Randomized
// Link     : https://leetcode.com/problems/insert-delete-getrandom-o1/
// Runtime  : 49 ms (beats 68%)
// Memory   : 92252000 (beats 68%)
// Language : c
// Copyright: (c) 2026 Srisakthi61. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

#define HASH_SIZE 10007

typedef struct Node {
    int val;
    int index;
    struct Node* next;
} Node;

typedef struct {
    int* nums;
    int size;
    int capacity;
    Node** table;
} RandomizedSet;

int getHash(int key) {
    int hash = key % HASH_SIZE;
    if (hash < 0) hash += HASH_SIZE;
    return hash;
}

void insertHash(Node** table, int val, int index) {
    int hash = getHash(val);
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->val = val;
    newNode->index = index;
    newNode->next = table[hash];
    table[hash] = newNode;
}

Node* findHash(Node** table, int val) {
    int hash = getHash(val);
    Node* curr = table[hash];
    while (curr) {
        if (curr->val == val) return curr;
        curr = curr->next;
    }
    return NULL;
}

void deleteHash(Node** table, int val) {
    int hash = getHash(val);
    Node* curr = table[hash];
    Node* prev = NULL;
    while (curr) {
        if (curr->val == val) {
            if (prev) prev->next = curr->next;
            else table[hash] = curr->next;
            free(curr);
            return;
        }
        prev = curr;
        curr = curr->next;
    }
}

RandomizedSet* randomizedSetCreate() {
    RandomizedSet* obj = (RandomizedSet*)malloc(sizeof(RandomizedSet));
    obj->capacity = 1000;
    obj->size = 0;
    obj->nums = (int*)malloc(obj->capacity * sizeof(int));
    obj->table = (Node**)calloc(HASH_SIZE, sizeof(Node*));
    return obj;
}

bool randomizedSetInsert(RandomizedSet* obj, int val) {
    if (findHash(obj->table, val) != NULL) return false;

    if (obj->size == obj->capacity) {
        obj->capacity *= 2;
        obj->nums = (int*)realloc(obj->nums, obj->capacity * sizeof(int));
    }

    obj->nums[obj->size] = val;
    insertHash(obj->table, val, obj->size);
    obj->size++;
    return true;
}

bool randomizedSetRemove(RandomizedSet* obj, int val) {
    Node* node = findHash(obj->table, val);
    if (node == NULL) return false;

    int index = node->index;
    int lastVal = obj->nums[obj->size - 1];

    obj->nums[index] = lastVal;
    Node* lastNode = findHash(obj->table, lastVal);
    if (lastNode) lastNode->index = index;

    deleteHash(obj->table, val);
    obj->size--;
    return true;
}

int randomizedSetGetRandom(RandomizedSet* obj) {
    return obj->nums[rand() % obj->size];
}

void randomizedSetFree(RandomizedSet* obj) {
    for (int i = 0; i < HASH_SIZE; i++) {
        Node* curr = obj->table[i];
        while (curr) {
            Node* temp = curr;
            curr = curr->next;
            free(temp);
        }
    }
    free(obj->table);
    free(obj->nums);
    free(obj);
}