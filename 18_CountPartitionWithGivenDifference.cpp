#include<bits/stdc++.h>
using namespace std;
/*
Part 1: Extra edge case for the problem Count Subsets with Sum K

In the problem Count Subsets with Sum K, the problem constraints stated that an array element is greater than 0, so the code we have written there works perfectly for the given constraints.

If the constraints mentioned that an array element can also be equal to 0 and the target sum can also be 0, then that code will fail. To understand it we will take an example:

Let the target arr = [0,0,1] and the target = 1.

The previous code will give us the answer 1 as it first takes the element arr[2] and then finds the answer by picking it. Then from the base condition, we will return 0 ( as the target will become 0 by picking 1). But for this question, the answer will be 4 with the following subsets({0,1},{0,1},{0,0,1} and {1}).
*/


// case 1 :
// Now, the following cases can arise when we are at index 0, if the target sum is 0 and the first index is also 0, like in case [0,1], we can form the subset in two ways, either by considering the first element or leaving it, so we can return 2.
// case 2:
// Else at index 0, if target == 0, and the first element is not 0, it means we will not pick the first element so we just return 1 way.
// OR if at index 0, when the first element is not 0, and the target is equal to the first element , then we will include it in the subset and we will return 1 way.
int findWaysUtil(int ind, int target, vector<int>& arr, vector<vector<int>> &dp){
    if(ind == 0){
            if(target==0 && arr[0]==0)
                return 2;
            if(target==0 || target == arr[0])
                return 1;
            return 0;
    }
    
    if(dp[ind][target]!=-1) return dp[ind][target];
        
    int notTaken = findWaysUtil(ind-1,target,arr,dp);
    int taken = 0;
    if(arr[ind]<=target)
        taken = findWaysUtil(ind-1,target-arr[ind],arr,dp);
        
    return dp[ind][target]= notTaken + taken;
}

int findWays(vector<int> &num, int k){
    int n = num.size();
    vector<vector<int>> dp(n,vector<int>(k+1,-1));
    return findWaysUtil(n-1,k,num,dp);
}


//--------------------------------------------------------------------------------------
// s1 - s2 = k
// s1 = totalsum - s2
// totalsum - s2 - s2 = k
// totalsum - 2*s2 = k
// totalsum - k = 2*s2
// s2 = (totalsum - k)/2

int mod =(int)1e9+7;
int countPartitionsUtil(int ind, int target, vector<int>& arr, vector<vector
<int>> &dp){

     if(ind == 0){
        if(target==0 && arr[0]==0)
            return 2;
        if(target==0 || target == arr[0])
            return 1;
        return 0;
    }
    
    if(dp[ind][target]!=-1)
        return dp[ind][target];
        
    int notTaken = countPartitionsUtil(ind-1,target,arr,dp);
    
    int taken = 0;
    if(arr[ind]<=target)
        taken = countPartitionsUtil(ind-1,target-arr[ind],arr,dp);
        
    return dp[ind][target]= (notTaken + taken)%mod;
}

int countPartitions(int d, vector<int>& arr){
    int n = arr.size();
    int totSum = 0;
    for(int i=0; i<arr.size();i++){
        totSum += arr[i];
    }
    
    //Checking for edge cases
    if(totSum-d<0) return 0;
    if((totSum-d)%2==1) return 0;
    
    int s2 = (totSum-d)/2;
    
    vector<vector<int>> dp(n,vector<int>(s2+1,-1));
    return countPartitionsUtil(n-1,s2,arr,dp);
}


// for optimization just optimize the countpartitions func.
// which is same as count subsets with K.