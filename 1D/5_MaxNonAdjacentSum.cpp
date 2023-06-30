#include<bits/stdc++.h>
using namespace std;
int recursion(int i, vector<int>& arr){
    if(i == 0){
        return arr[0];
    }
    if(i < 0)
        return 0;

    int pick = arr[i] + recursion(i - 2, arr);
    int notpick = recursion(i - 1, arr);
    return max(pick, notpick);
}

int memo(int i, vector<int>& arr, vector<int>& dp){
    if(i == 0){
        return arr[0];
    }
    if(i < 0)
        return 0;

    if(dp[i] != -1)
        return dp[i];

    int pick = arr[i] + recursion(i - 2, arr);
    int notpick = recursion(i - 1, arr);
    return dp[i] = max(pick, notpick);
}

int tabulation(int n, vector<int>& arr){
    vector<int> dp(n, 0);
    dp[0] = arr[0];
    for (int i = 1; i < n; i++){
        int notpick = dp[i - 1];
        int pick = INT_MIN;
        if(i-1>=0){
            pick = arr[i] + dp[i - 2];
        }
        dp[i] = max(pick, notpick);
    }
    return dp[n - 1];
}

int spaceoptimization(int n, vector<int>& arr){
    int prevprev = arr[0], prev = max(arr[1], arr[0]), curr;
    
    for (int i = 2; i <= n; i++){
        int notpick = prev;
        int pick = INT_MIN;
        if(i-1 >= 0){
            pick = arr[i] + prevprev;
        }
        curr = max(pick, notpick);
        prevprev = prev;
        prev = curr;
    }
    return curr;
}