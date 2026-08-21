// ──────────────────────────────────────────────────
// Problem  : 1283. Find the Smallest Divisor Given a Threshold
// Difficulty: Medium
// Tags     : Array, Binary Search
// Link     : https://leetcode.com/problems/find-the-smallest-divisor-given-a-threshold/
// Runtime  : 7 ms (beats 83%)
// Memory   : 50756000 (beats 95%)
// Language : java
// Copyright: (c) 2026 Srisakthi61. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

class Solution {
    boolean possible(int []nums,int threshold,int div){
        int sum=0;
        for(int i=0; i<nums.length; i++){
            sum+=(nums[i]+div-1)/div;
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