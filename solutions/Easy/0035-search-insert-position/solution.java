// ──────────────────────────────────────────────────
// Problem  : 35. Search Insert Position
// Difficulty: Easy
// Tags     : Array, Binary Search
// Link     : https://leetcode.com/problems/search-insert-position/
// Runtime  : 0 ms (beats 100%)
// Memory   : 44644000 (beats 67%)
// Language : java
// Copyright: (c) 2026 Srisakthi61. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

class Solution {
    public int searchInsert(int[] nums, int target) {
        //tc:o(log n)
        int low=0;
        int high=nums.length-1;
        int mid=0;
        while(low <= high){
            mid=(low+high)/2;
            if(nums[mid]==target){
                return mid;
            }else if(nums[mid]>target){
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        return low;
        /*(another method: tc-o(n)
        for(int i=0; i<nums.length; i++){
            if(target <nums[i]){
                return i;
            }
        }
        return nums.length;//edge case*/
    }
} 
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        /*for(int i=0; i<nums.length; i++){
            if(nums[i]==target){
                return i;
            }
        }
        for(int i=0; i<nums.length; i++){
            if(nums[i]>target){
                return i;
            }
        }
        return nums.length;

    }
}*/