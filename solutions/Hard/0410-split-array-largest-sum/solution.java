// ──────────────────────────────────────────────────
// Problem  : 410. Split Array Largest Sum
// Difficulty: Hard
// Tags     : Array, Binary Search, Dynamic Programming, Greedy, Prefix Sum
// Link     : https://leetcode.com/problems/split-array-largest-sum/
// Runtime  : 0 ms (beats 100%)
// Memory   : 42876000 (beats 84%)
// Language : java
// Copyright: (c) 2026 Srisakthi61. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

class Solution {
    boolean func(int [] nums,int k,int max){
        int count_arr=1;
        int sum=0;
        for(int i=0; i<nums.length; i++){
            sum+=nums[i];
            if(sum >max){
                count_arr++;
                sum=nums[i];
            }
        }
        if(count_arr > k){
            return false;
        }else{
            return true;
        }
    }
    public int splitArray(int[] nums, int k) {
        int max=0;
        int sum=0;
        for(int c:nums){
            max=Math.max(max,c);
            sum+=c;
        }
        int low=max;
        int high=sum;
        while(low <= high){
            int mid=(low+high)/2;
            if(func(nums, k ,mid)){
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        return low;
    }
}