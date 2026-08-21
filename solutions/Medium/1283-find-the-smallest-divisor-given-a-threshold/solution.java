// ──────────────────────────────────────────────────
// Problem  : 1283. Find the Smallest Divisor Given a Threshold
// Difficulty: Medium
// Tags     : Array, Binary Search
// Link     : https://leetcode.com/problems/find-the-smallest-divisor-given-a-threshold/
// Runtime  : 29 ms (beats 34%)
// Memory   : 51092000 (beats 55%)
// Language : java
// Copyright: (c) 2026 Srisakthi61. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

class Solution {
    boolean possible(int []nums,int threshold,int div){
        long sum=0;
        for(int i=0; i<nums.length; i++){
            sum+=(long)Math.ceil((double)nums[i]/div);
        }
        if(sum <= threshold){
            return true;
        }else{
            return false;
        }
    }
    public int smallestDivisor(int[] nums, int threshold) {
        int max=0;
        for(int c: nums){
            max=Math.max(max,c);
        }
        
        int low=1;
        int high=max;
        while(low<=high){
        int mid=(low+high)/2;
        if(possible(nums,threshold,mid)){
            high=mid-1;
        }else{
            low=mid+1;
        }
        }
        return low;
    }
}