// ──────────────────────────────────────────────────
// Problem  : 1482. Minimum Number of Days to Make m Bouquets
// Difficulty: Medium
// Tags     : Array, Binary Search
// Link     : https://leetcode.com/problems/minimum-number-of-days-to-make-m-bouquets/
// Runtime  : 17 ms (beats 73%)
// Memory   : 82548000 (beats 67%)
// Language : java
// Copyright: (c) 2026 Srisakthi61. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

class Solution {
    boolean possible(int[] bloomDay, int m, int k, int day){
        int flower=0;
        int no_of_bq=0;
            for(int i=0; i<bloomDay.length; i++){
                if(bloomDay[i]<=day){
                    flower++;
                }else{
                    no_of_bq+=flower/k;
                    flower=0;
                }
            }
            no_of_bq+=flower/k;
            if(no_of_bq>=m){
                return true;
            }else{
                return false;
            }
    }
    public int minDays(int[] bloomDay, int m, int k) {
        int max=0;
        int min=Integer.MAX_VALUE;
        for(int c:bloomDay){
            max=Math.max(max,c);
            min=Math.min(min,c);
        }
        int low=min;
        int high=max;
        if(bloomDay.length <(long) m*k){
            return -1;
        }
        while(low<=high){
            int mid=(low+high)/2;
            if(possible(bloomDay, m, k, mid)){
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        return low;
    }
}