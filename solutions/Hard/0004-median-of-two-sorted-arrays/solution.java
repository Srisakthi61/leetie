// ──────────────────────────────────────────────────
// Problem  : 4. Median of Two Sorted Arrays
// Difficulty: Hard
// Tags     : Array, Binary Search, Divide and Conquer
// Link     : https://leetcode.com/problems/median-of-two-sorted-arrays/
// Runtime  : 1 ms (beats 100%)
// Memory   : 48632000 (beats 86%)
// Language : java
// Copyright: (c) 2026 Srisakthi61. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

class Solution {
    public double findMedianSortedArrays(int[] nums1, int[] nums2) {
        int n1=nums1.length;
        int n2=nums2.length;
        if(n1 >n2) return findMedianSortedArrays(nums2,nums1);
        int left=(n1+n2+1)/2;
        int low=0;
        int high=n1;
        int n=n1+n2;
        while(low<=high){
            int mid1=(low+high)/2;
            int mid2=left-mid1;
            int l1=Integer.MIN_VALUE, l2=Integer.MIN_VALUE;
            int r1=Integer.MAX_VALUE, r2=Integer.MAX_VALUE;
            if(mid1 <n1) r1=nums1[mid1];
            if(mid2 <n2) r2=nums2[mid2];
            if(mid1-1 >= 0) l1=nums1[mid1-1];
            if(mid2-1 >= 0) l2=nums2[mid2-1];
            if(l1<=r2 && l2<=r1){
                if(n%2 ==1) return Math.max(l1,l2);
                return ((double)Math.max(l1,l2)+Math.min(r1,r2))/2.0;
            }else if(l1 > r2){
                high=mid1-1;
            }else{
                low=mid1+1;
            }
        }
    return -1;
    }
    
}

/*brute force 1
class Solution {
    public double findMedianSortedArrays(int[] nums1, int[] nums2) {
      int i=0;
      int j=0;
      int k=0;
      int n1=nums1.length;
      int n2=nums2.length;
      int n=n1+n2;
      int[] nums3=new int[n1+n2];
      while(i<n1 && j<n2){
        if(nums1[i]<nums2[j]){
            nums3[k]=nums1[i];
            i++;
            k++;
        }else{
            nums3[k]=nums2[j];
            j++;
            k++;
        }
      }
      while(i<n1){
        nums3[k]=nums1[i];
        i++;
        k++;
      }
      while(j<n2){
        nums3[k]=nums2[j];
        j++;
        k++;
      }
      if(n%2 == 0){
        return (double)((double)nums3[n/2]+nums3[n/2-1])/2;
      }else{
        return (double)nums3[n/2];
      }
    }
}tc->o(n1+n2) and sc->o(n1+n2)

brute force approach 2
class Solution {
    public double findMedianSortedArrays(int[] nums1, int[] nums2) {
      int i=0;
      int j=0;
      int k=0;
      int n1=nums1.length;
      int n2=nums2.length;
      int n=n1+n2;
      int count=0;
      int ind2=n/2;
      int ind1=ind2 -1;
      int ele1=-1;
      int ele2=-1;
      while(i<n1 && j<n2){
        if(nums1[i]<nums2[j]){
            if(count==ind1) ele1 = nums1[i];
            if(count==ind2) ele2 = nums1[i];
            i++;
            count++;
        }else{
            if(count==ind1) ele1 = nums2[j];
            if(count==ind2) ele2 = nums2[j];
            j++;
            count++;
        }
      }
      while(i<n1){
        if(count==ind1) ele1 = nums1[i];
        if(count==ind2) ele2 = nums1[i];
            i++;
            count++;
      }
      while(j<n2){
        if(count==ind1) ele1 = nums2[j];
        if(count==ind2) ele2 = nums2[j];
            j++;
            count++;
      }
      if(n%2 == 0){
        return ((double)ele1+ele2)/2;
      }else{
        return (double)ele2;
      }
    }
}tc->o(n1+n2) sc->(1)*/