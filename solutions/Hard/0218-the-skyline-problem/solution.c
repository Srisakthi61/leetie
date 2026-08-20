// ──────────────────────────────────────────────────
// Problem  : 218. The Skyline Problem
// Difficulty: Hard
// Tags     : Array, Divide and Conquer, Binary Indexed Tree, Segment Tree, Sweep Line, Sorting, Heap (Priority Queue), Ordered Set
// Link     : https://leetcode.com/problems/the-skyline-problem/
// Runtime  : 63 ms (beats 55%)
// Memory   : 24804000 (beats 73%)
// Language : c
// Copyright: (c) 2026 Srisakthi61. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int x;
    int height;
} Event;

int compareEvents(const void* a, const void* b) {
    Event* e1 = (Event*)a;
    Event* e2 = (Event*)b;
    if (e1->x != e2->x) {
        return e1->x - e2->x;
    }
    return e2->height - e1->height;
}

typedef struct {
    int* data;
    int size;
    int capacity;
} MaxHeap;

MaxHeap* createHeap(int capacity) {
    MaxHeap* heap = (MaxHeap*)malloc(sizeof(MaxHeap));
    heap->data = (int*)malloc(sizeof(int) * capacity);
    heap->size = 0;
    heap->capacity = capacity;
    return heap;
}

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void push(MaxHeap* heap, int val) {
    heap->data[heap->size] = val;
    int curr = heap->size;
    heap->size++;
    
    while (curr > 0) {
        int parent = (curr - 1) / 2;
        if (heap->data[curr] > heap->data[parent]) {
            swap(&heap->data[curr], &heap->data[parent]);
            curr = parent;
        } else {
            break;
        }
    }
}

void heapify(MaxHeap* heap, int idx) {
    int largest = idx;
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;

    if (left < heap->size && heap->data[left] > heap->data[largest])
        largest = left;
    if (right < heap->size && heap->data[right] > heap->data[largest])
        largest = right;

    if (largest != idx) {
        swap(&heap->data[idx], &heap->data[largest]);
        heapify(heap, largest);
    }
}

int getMax(MaxHeap* heap) {
    return heap->size > 0 ? heap->data[0] : 0;
}

void removeVal(MaxHeap* heap, int val) {
    for (int i = 0; i < heap->size; i++) {
        if (heap->data[i] == val) {
            heap->data[i] = heap->data[heap->size - 1];
            heap->size--;
            heapify(heap, i);
            break;
        }
    }
}

int** getSkyline(int** buildings, int buildingsSize, int* buildingsColSize, int* returnSize, int** returnColumnSizes) {
    int eventsSize = buildingsSize * 2;
    Event* events = (Event*)malloc(sizeof(Event) * eventsSize);

    int idx = 0;
    for (int i = 0; i < buildingsSize; i++) {
        events[idx].x = buildings[i][0];
        events[idx].height = buildings[i][2]; // Start of building (positive height)
        idx++;

        events[idx].x = buildings[i][1];
        events[idx].height = -buildings[i][2]; // End of building (negative height)
        idx++;
    }

    qsort(events, eventsSize, sizeof(Event), compareEvents);

    MaxHeap* heap = createHeap(eventsSize + 1);
    push(heap, 0);

    int** result = (int**)malloc(sizeof(int*) * eventsSize);
    *returnColumnSizes = (int*)malloc(sizeof(int) * eventsSize);
    *returnSize = 0;

    int prevMax = 0;

    for (int i = 0; i < eventsSize; i++) {
        int x = events[i].x;
        int h = events[i].height;

        if (h > 0) {
            push(heap, h);
        } else {
            removeVal(heap, -h);
        }

        int currentMax = getMax(heap);
        if (currentMax != prevMax) {
            result[*returnSize] = (int*)malloc(sizeof(int) * 2);
            result[*returnSize][0] = x;
            result[*returnSize][1] = currentMax;
            (*returnColumnSizes)[*returnSize] = 2;
            (*returnSize)++;
            prevMax = currentMax;
        }
    }

    free(events);
    free(heap->data);
    free(heap);

    return result;
}