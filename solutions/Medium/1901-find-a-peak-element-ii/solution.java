// ──────────────────────────────────────────────────
// Problem  : 1901. Find a Peak Element II
// Difficulty: Medium
// Tags     : Array, Binary Search, Matrix
// Link     : https://leetcode.com/problems/find-a-peak-element-ii/
// Runtime  : 0 ms (beats 100%)
// Memory   : 119000000 (beats 89%)
// Language : java
// Copyright: (c) 2026 Srisakthi61. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

class Solution {
    int max(int[][] arr,int n, int col){
        int max_val=-1;
        int ind=-1;
        for(int i=0; i<n; i++){
            if(arr[i][col] > max_val){
                max_val=arr[i][col];
                ind=i;
            }
        }
        return ind;
    }
    public int[] findPeakGrid(int[][] mat) {
        int n=mat.length;
        int m=mat[0].length;
        int low=0;
        int high=m-1;
        int[] ans=new int[2];
        while(low <=high){
            int mid=(low+high)/2;
            int row=max(mat,n,mid);
            int left=mid-1 >= 0 ? mat[row][mid-1]:-1;
            int right=mid+1 <m ? mat[row][mid+1]:-1;
            if(mat[row][mid]>left && mat[row][mid]>right){
                ans[0]=row;
                ans[1]=mid;
                return ans;
            }else if(mat[row][mid]<left){
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        return ans;
    }
}