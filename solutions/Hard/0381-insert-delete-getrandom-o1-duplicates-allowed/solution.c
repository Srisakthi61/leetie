// ──────────────────────────────────────────────────
// Problem  : 381. Insert Delete GetRandom O(1) - Duplicates allowed
// Difficulty: Hard
// Tags     : Array, Hash Table, Math, Design, Randomized
// Link     : https://leetcode.com/problems/insert-delete-getrandom-o1-duplicates-allowed/
// Runtime  : 69 ms (beats 29%)
// Memory   : 95652000 (beats 83%)
// Language : c
// Copyright: (c) 2026 Srisakthi61. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

typedef struct {
    int val;
    int pos;
} NumEntry;

typedef struct {
    int key;
    int* indices;
    int count;
    int capacity;
    UT_hash_handle hh;
} HashItem;

typedef struct {
    NumEntry* nums;
    int nums_count;
    int nums_capacity;
    HashItem* map;
} RandomizedCollection;

RandomizedCollection* randomizedCollectionCreate() {
    RandomizedCollection* obj = malloc(sizeof(RandomizedCollection));
    obj->nums = NULL;
    obj->nums_count = 0;
    obj->nums_capacity = 0;
    obj->map = NULL;
    return obj;
}

bool randomizedCollectionInsert(RandomizedCollection* obj, int val) {
    bool res = false;
    HashItem* item = NULL;
    HASH_FIND_INT(obj->map, &val, item);
    
    if (!item) {
        res = true;
        item = malloc(sizeof(HashItem));
        item->key = val;
        item->count = 0;
        item->capacity = 4;
        item->indices = malloc(item->capacity * sizeof(int));
        HASH_ADD_INT(obj->map, key, item);
    } else if (item->count == 0) {
        res = true;
    }
    
    if (item->count == item->capacity) {
        item->capacity *= 2;
        item->indices = realloc(item->indices, item->capacity * sizeof(int));
    }
    
    if (obj->nums_count == obj->nums_capacity) {
        obj->nums_capacity = obj->nums_capacity == 0 ? 16 : obj->nums_capacity * 2;
        obj->nums = realloc(obj->nums, obj->nums_capacity * sizeof(NumEntry));
    }
    
    int idx = obj->nums_count;
    int pos = item->count;
    item->indices[pos] = idx;
    item->count++;
    
    obj->nums[idx].val = val;
    obj->nums[idx].pos = pos;
    obj->nums_count++;
    
    return res;
}

bool randomizedCollectionRemove(RandomizedCollection* obj, int val) {
    HashItem* item = NULL;
    HASH_FIND_INT(obj->map, &val, item);
    
    if (!item || item->count == 0) {
        return false;
    }
    
    int idx_to_remove = item->indices[item->count - 1];
    item->count--;
    
    if (idx_to_remove != obj->nums_count - 1) {
        NumEntry last_entry = obj->nums[obj->nums_count - 1];
        obj->nums[idx_to_remove] = last_entry;
        
        HashItem* last_item = NULL;
        HASH_FIND_INT(obj->map, &last_entry.val, last_item);
        last_item->indices[last_entry.pos] = idx_to_remove;
    }
    
    obj->nums_count--;
    
    if (item->count == 0) {
        HASH_DEL(obj->map, item);
        free(item->indices);
        free(item);
    }
    
    return true;
}

int randomizedCollectionGetRandom(RandomizedCollection* obj) {
    int random_idx = rand() % obj->nums_count;
    return obj->nums[random_idx].val;
}

void randomizedCollectionFree(RandomizedCollection* obj) {
    HashItem *item, *tmp;
    HASH_ITER(hh, obj->map, item, tmp) {
        HASH_DEL(obj->map, item);
        free(item->indices);
        free(item);
    }
    free(obj->nums);
    free(obj);
}