// ──────────────────────────────────────────────────
// Problem  : 1482. Minimum Number of Days to Make m Bouquets
// Difficulty: Medium
// Tags     : Array, Binary Search
// Link     : https://leetcode.com/problems/minimum-number-of-days-to-make-m-bouquets/
// Runtime  : 14 ms (beats 99%)
// Memory   : 82448000 (beats 84%)
// Language : java
// Copyright: (c) 2026 Srisakthi61. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

class Solution {
    public int minDays(int[] bloomDay, int m, int k) {
        int low=1;
        int max=0;
        if(bloomDay.length <(long)m*k){
            return -1;
        }
        for(int c:bloomDay){
            max=Math.max(max,c);
        }
        int high=max;
        while(low<=high){
            int mid=(low+high)/2;
            int flower=0;
            int bq=0;
            for(int i=0; i<bloomDay.length; i++){
                if(bloomDay[i]<=mid){
                    flower++;
                }else{
                    bq+=flower/k;
                    flower=0;
                }
            }
            bq+=flower/k;
            if(bq>=m){
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        return low;
    }
}