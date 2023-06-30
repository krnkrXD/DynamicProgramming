#include<bits/stdc++.h>
using namespace std;
// A subset/subsequence is a contiguous or non-contiguous part of an array, where elements appear in the same order as the original array.
bool recursion(int i, int target, vector<int> arr){
    if(i < 0 and target != 0) return false;
    // base case
    if(i == 0){
        if(arr[0] == target){
            return true;
        }
        else{
            return false;
        }
    }
    // matches target
    if(arr[0] == target){
        return true;
    }
    
    // possible stuffs
    int pick = recursion(i - 1, target - arr[i], arr);
    int notpick = recursion(i - 1, target, arr);
    return pick || notpick;
}

bool memo(int i, int target, vector<int> arr, vector<vector<int>>& dp){
    // base case
    if(target == 0){
        return true;
    }
    if(i == 0){
        return arr[0] == target;
    }
    
    if(dp[i][target] != -1) return dp[i][target];
    
    // possible stuffs
    int pick = false;
    if(arr[i] <= target){
        pick = recursion(i - 1, target - arr[i], arr);
    }
    int notpick = recursion(i - 1, target, arr);
    return dp[i][target] = pick || notpick;
}
// i->[0,n-1]
// target->[1,target]
// vector<vector<int>> dp(n, vector<int>(target+1, -1));

int dp(vector<int> arr, int n, int target){
    vector<vector<int>> dp(n, vector<int>(target + 1));

    for (int i = 0; i < n;i++){
        dp[i][0] = true;    // target == 0
    }
    if(arr[0] <= target){
        dp[0][arr[0]] = true;
    }

    for (int i = 1; i < n; i++){
        for (int tar = 1; tar <= target; i++){
            // possible stuffs
            int pick = false;
            if(arr[i] <= tar){
                pick = dp[i - 1][tar - arr[i]];
            }
            int notpick = dp[i - 1][tar];
            dp[i][tar] = pick || notpick;
        }
    }

    return dp[n - 1][target];
}

int spaceoptimize(vector<int> arr, int n, int target){
    int n = arr.size();
    vector<bool> prev(target + 1, false);

    prev[0] = true;    // target == 0
    if(arr[0] <= target){
        prev[arr[0]] = true;
    }

    for (int i = 1; i < n; i++){
        vector<bool> curr(target + 1, false);
        curr[0] = true;
        for (int tar = 1; tar <= target; tar++){
            // possible stuffs
            int pick = false;
            if(arr[i] <= tar){
                pick = prev[tar - arr[i]];
            }
            int notpick = prev[tar];
            curr[tar] = pick || notpick;
        }
        prev = curr;
    }

    return prev[target];
}
