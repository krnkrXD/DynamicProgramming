#include <bits/stdc++.h>
using namespace std;

// Using SubsetSumTarget
// s1 - s2 = target
// s1 = totalsum - s2
// totalsum - s2 - s2 = target
// s2 = (totalsum - target)/2
int countPartitionsUtil(int ind, int target, vector<int>& arr, vector<vector<int>> 
&dp){
     if(ind == 0){
        if(target==0 && arr[0]==0) return 2; // two ways
        if(target==0 || target == arr[0]) return 1; // one way
        return 0;
    }
    
    if(dp[ind][target]!=-1) return dp[ind][target];
        
    int notTaken = countPartitionsUtil(ind-1,target,arr,dp);
    int taken = 0;
    if(arr[ind]<=target)
        taken = countPartitionsUtil(ind-1,target-arr[ind],arr,dp);
    return dp[ind][target]= (notTaken + taken);
}

int targetSum(int n,int target, vector<int>& arr){
    int totSum = 0;
    for(int i=0; i<arr.size();i++){
        totSum += arr[i];
    }
    
    //Checking for edge cases
    if(totSum-target<0) return 0;
    if((totSum-target)%2==1) return 0;
    
    int s2 = (totSum-target)/2;
    
    vector<vector<int>> dp(n,vector<int>(s2+1,-1));
    return countPartitionsUtil(n-1,s2,arr,dp);
}