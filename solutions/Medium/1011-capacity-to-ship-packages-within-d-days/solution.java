// ──────────────────────────────────────────────────
// Problem  : 1011. Capacity To Ship Packages Within D Days
// Difficulty: Medium
// Tags     : Array, Binary Search
// Link     : https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/
// Runtime  : 11 ms (beats 66%)
// Memory   : 50024000 (beats 76%)
// Language : java
// Copyright: (c) 2026 Srisakthi61. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

class Solution {
    int func(int [] weights,int cap){
        int days_req=1;
        int load=0;
        for(int i=0; i<weights.length; i++){
            load+=weights[i];
            if(load >cap){
                days_req++;
                load=weights[i];
            }
        }
        return days_req;
    }
    public int shipWithinDays(int[] weights, int days) {
        int max=0;
        int sum=0;
        for(int c: weights){
            max=Math.max(max,c);
            sum+=c;
        }
        int low=max;
        int high=sum;
        while(low <= high){
            int mid=(low+high)/2;
            int daysReq=func(weights,mid);
            if(daysReq <= days){
                high=mid-1;
            }else{
                low=mid+1;
            }
        }   
        return low;     
    }
}

/*int ans=0;
        for(int cap=max; cap<=sum; cap++){
            int days_req=days_req(weights,days);
            if(days_req <=cap){
                ans=days_req;
            }else{
                break;
            }
        }*/