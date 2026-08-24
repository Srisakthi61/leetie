// ──────────────────────────────────────────────────
// Problem  : 1539. Kth Missing Positive Number
// Difficulty: Easy
// Tags     : Array, Binary Search
// Link     : https://leetcode.com/problems/kth-missing-positive-number/
// Runtime  : 0 ms (beats 100%)
// Memory   : 44568000 (beats 58%)
// Language : java
// Copyright: (c) 2026 Srisakthi61. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

class Solution {
    public int findKthPositive(int[] arr, int k) {
        int low=0;
        int high=arr.length-1;
        while(low <= high){
            int mid=(low+high)/2;
            int missing=arr[mid]-(mid+1);
            if(missing <k){
                low=mid+1;
            }else{
                high=mid-1;
            }
        }
        return low+k;
    }
}