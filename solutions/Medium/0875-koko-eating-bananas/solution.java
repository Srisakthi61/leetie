// ──────────────────────────────────────────────────
// Problem  : 875. Koko Eating Bananas
// Difficulty: Medium
// Tags     : Array, Binary Search
// Link     : https://leetcode.com/problems/koko-eating-bananas/
// Runtime  : 22 ms (beats 25%)
// Memory   : 47900000 (beats 60%)
// Language : java
// Copyright: (c) 2026 Srisakthi61. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

class Solution {
    public int minEatingSpeed(int[] piles, int h) {
       int max=0;
       for(int c:piles){
            max=Math.max(max,c);
       }
       int ans=0;
       long total=0;
       int low=1;
       int high=max;
       while(low <=high){
        int mid=(low+high)/2;
            for(int i=0;i<piles.length; i++){
                total+=(long)Math.ceil((double)piles[i]/mid);
            }
            if(total<=h){
                ans=mid;
                high=mid-1;
            }else{
                low=mid+1;
            }
            total=0;
       }
       return ans;
    }
}





//brute force
        /*int max=0;
        for(int c:piles){
            max=Math.max(max,c);
        }
        int total=0;
        for(int k=1; k<=max;k++){
            for(int j=0; j<piles.length; j++){
                total+=(int)Math.ceil((double)piles[j]/k);
            }
            if(total<=h){
                return k;
            }
            total=0;
        }
        return 0;
    */
