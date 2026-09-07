// ──────────────────────────────────────────────────
// Problem  : 240. Search a 2D Matrix II
// Difficulty: Medium
// Tags     : Array, Binary Search, Divide and Conquer, Matrix
// Link     : https://leetcode.com/problems/search-a-2d-matrix-ii/
// Runtime  : 3 ms (beats 86%)
// Memory   : 48172000 (beats 65%)
// Language : java
// Copyright: (c) 2026 Srisakthi61. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

class Solution {
    boolean possible(int[] arr,int target,int m){
        int low=0;
        int high=m-1;
        while(low<=high){
            int mid=(low+high)/2;
            if(arr[mid]==target){
                return true;
            }else if(arr[mid] > target){
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        return false;
    }
    public boolean searchMatrix(int[][] matrix, int target) {
        int n=matrix.length;
        int m=matrix[0].length;
        for(int i=0; i<n; i++){
            boolean res=possible(matrix[i],target,m);
            if(res==true){
                return true;
            }
        }
        return false;
    }
}