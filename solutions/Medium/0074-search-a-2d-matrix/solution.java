// ──────────────────────────────────────────────────
// Problem  : 74. Search a 2D Matrix
// Difficulty: Medium
// Tags     : Array, Binary Search, Matrix
// Link     : https://leetcode.com/problems/search-a-2d-matrix/
// Runtime  : 0 ms (beats 100%)
// Memory   : 43992000 (beats 44%)
// Language : java
// Copyright: (c) 2026 Srisakthi61. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

class Solution {
    public boolean searchMatrix(int[][] matrix, int target) {
        int n=matrix.length;
        int m=matrix[0].length;
        int low=0;
        int high=m*n-1;
        while(low<=high){
            int mid=(low+high)/2;
            int row=mid/m;
            int col=mid % m;
            if(matrix[row][col]==target){
                return true;
            }else if(matrix[row][col]>target){
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        return false;
    }
}

/*class Solution {
    boolean possible(int[] arr,int target,int m){
        int low=0;
        int high=m-1;
        while(low<=high){
            int mid=(low+high)/2;
            if(arr[mid]==target){
                return true;
            }else if(mid > target){
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
}*/