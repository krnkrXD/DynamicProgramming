#include<bits/stdc++.h>
using namespace std;

//generate all the subsequences, check the increasing order, store the size.
// O(2^N) exponential.

int solve(int i, int prev_i, vector<int>& arr, int n, vector<vector<int>>& dp){
    // base cas
    if(i == n) return 0;

    if(dp[i][prev_i+1] != -1) return dp[i][prev_i+1];
    
    int pick = 0, notpick = 0;
    if(prev_i == -1 or arr[prev_i] < arr[i]){
        pick = 1 + solve(i + 1, i, arr, n, dp);
    }
    notpick = solve(i + 1, prev_i, arr, n, dp);
    return dp[i][prev_i+1] = max(pick, notpick);
}
int lengthOfLIS(vector<int>& nums) {
    int n = nums.size();
    vector<vector<int>> dp(n, vector<int>(n+1, -1));
    return solve(0, -1, nums, n, dp);
}
// Time Complexity : O(N*N)
// Space Complexity : O(N*N) + O(N)


// ind = (n) -> 0        
// previ = (ind - 1) -> -1 
// coordinate shifting
// ind = (n) -> 0
// previ = (ind -1 + 1) -> -1 + 1 = (ind) -> 0
int lengthOfLIS(vector<int>& arr){
    int n = arr.size();
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
    for (int i = n - 1; i >= 0; i--){
        for (int prev_i = i - 1; prev_i >= -1; prev_i--){
            int pick = 0, notpick = 0;
            if(prev_i == -1 or arr[prev_i] < arr[i]){
                pick = 1 + dp[i + 1][i + 1];
            }
            notpick = dp[i + 1][prev_i + 1];
            dp[i][prev_i+1] = max(pick, notpick);
        }
    }
    return dp[0][-1+1];
}
// Time Complexity : O(N*N)
// Space Complexity : O(N*N), recursion stack removed


int lengthOfLIS(vector<int>& arr){
    int n = arr.size();
    vector<int> next(n + 1, 0), cur(n + 1, 0);
    for (int ind = n - 1; ind >= 0; ind--){
        for (int prev_index = ind - 1; prev_index >= -1; prev_index--){
            int notTake = 0 + next[prev_index + 1];
            int take = 0;
            if(prev_index == -1 || arr[ind] > arr[prev_index]){
                take = 1 + next[ind + 1];
            }
            cur[prev_index + 1] = max(notTake, take);
        }
        next = cur;
    }
    return cur[0];
}
// Time Complexity : O(N*N)
// Space Complexity : O(N) + O(N)

int lengthOfLIS(vector<int>& arr){
    int n = arr.size(), maxi = 1;
    vector<int> dp(n + 1, 0);
    for (int i = 0; i < n; i++){
        for (int prev = 0; prev < i; prev++){
            if(arr[prev] < arr[i]){
                dp[i] = max(dp[i], 1 + dp[prev]);
            }
        }
        maxi = max(maxi, dp[i]);
    }
    return maxi;
}
// Time Complexity : O(N*N)
// Space Complexity : O(N)