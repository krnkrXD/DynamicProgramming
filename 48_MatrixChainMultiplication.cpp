#include <bits/stdc++.h>
using namespace std;

int recursion(vector<int>& arr, int i, int j){
    // base condition
    if(i == j) return 0;
        
    int mini = INT_MAX;
    // partioning loop
    for(int k = i; k<= j-1; k++){
        int ans = recursion(arr,i,k) + recursion(arr, k+1,j) + arr[i-1]*arr[k]*arr[j];
        mini = min(mini,ans);
    }
    return mini;
}
int matrixMultiplication_recursion(vector<int>& arr, int N){
    int i =1;
    int j = N-1;
    return recursion(arr,i,j); 
}


int memoization(vector<int>& arr, int i, int j, vector<vector<int>>& dp){
    // base condition
    if(i == j) return 0;
    
    if(dp[i][j]!=-1) return dp[i][j];
    
    int mini = INT_MAX;
    // partioning loop
    for(int k = i; k<= j-1; k++){
        int ans = memoization(arr,i,k,dp) + memoization(arr, k+1,j,dp) + arr[i-1]*arr[k]*arr[j];
        mini = min(mini,ans);   
    }
    return mini;
}
int matrixMultiplication_memo(vector<int>& arr, int N){
    vector<vector<int>> dp(N,vector<int>(N,-1));
    int i =1, j = N-1;
    return memoization(arr,i,j,dp);  
}