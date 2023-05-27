#include<bits/stdc++.h>
using namespace std;
// A subset/subsequence is a contiguous or non-contiguous part of an array, where elements appear in the same order as the original array.
// same as subset sum target.
// just return 1 or 0.
int recursion(int i, int target, vector<int> arr){
    if(target == 0){
        return 1;
    }
    if(i == 0){
        return arr[0] == target;
    }
    
    // possible stuffs
    int pick = 0;
    if(arr[i] <= target){
        pick = recursion(i - 1, target - arr[i], arr);
    }
    int notpick = recursion(i - 1, target, arr);
    return pick + notpick;
}

int memo(int i, int target, vector<int> arr, vector<vector<int>>& dp){
    if(target == 0){
        return 1;
    }
    if(i == 0){
        return arr[0] == target;
    }
    
    if(dp[i][target] != -1) return dp[i][target];

    // possible stuffs
    int pick = 0;
    if(arr[i] <= target){
        pick = memo(i - 1, target - arr[i], arr, dp);
    }
    int notpick = memo(i - 1, target, arr, dp);
    return dp[i][target] = pick + notpick;
}

int dp(vector<int> arr, int n, int target){
    vector<vector<int>> dp(n, vector<int>(target + 1));

    for (int i = 0; i < n;i++){
        dp[i][0] = 1;    // target == 0
    }
    if(arr[0] <= target){
        dp[0][arr[0]] = 1;
    }

    for (int i = 1; i < n; i++){
        for (int tar = 1; tar <= target; i++){
            // possible stuffs
            int pick = 0;
            if(arr[i] <= tar){
                pick = dp[i - 1][tar - arr[i]];
            }
            int notpick = dp[i - 1][tar];
            dp[i][tar] = pick + notpick;
        }
    }

    return dp[n - 1][target];
}


int spaceoptimize(vector<int> arr, int n, int target){
    vector<int> prev(target + 1);

    for (int i = 0; i < n;i++){
        prev[0] = 1;    // target == 0
    }
    if(arr[0] <= target){
        prev[arr[0]] = 1;
    }

    for (int i = 1; i < n; i++){
        vector<int> curr(target + 1);
        for (int tar = 1; tar <= target; i++){
            // possible stuffs
            int pick = 0;
            if(arr[i] <= tar){
                pick = prev[tar - arr[i]];
            }
            int notpick = prev[tar];
            curr[tar] = pick + notpick;
        }
        prev = curr;
    }

    return prev[target];
}