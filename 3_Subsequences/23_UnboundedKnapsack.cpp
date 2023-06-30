#include <bits/stdc++.h>
using namespace std;

int recursion(int i, int W, int N, vector<int> wt, vector<int> val){
    // if(W==0) return 0;  personal choice to add this, just reduce the no of calls
    if(i == 0){
        if(wt[i] <= W) return val[i];
        else return 0;
    }
    // possible stuffs
    int notpick = recursion(i - 1, W, N, wt, val);
    int pick = INT_MIN;
    if(wt[i] <= W){
        pick = val[i] + recursion(i, W - wt[i], N, wt, val);
    }
    return max(notpick, pick);
}

int memo(int i, int W, int N, vector<int> wt, vector<int> val, vector<vector<int>>& dp){
    // if(W==0) return 0;  personal choice to add this, just reduce the no of calls
    if(i == 0){
        if(wt[0] <= W) return (W / wt[i]) * val[0];
        else return 0;
    }

    if(dp[i][W] != -1) return dp[i][W];

    // possible stuffs
    int notpick = recursion(i - 1, W, N, wt, val);
    int pick = INT_MIN;
    if(wt[i] <= W){
        pick = val[i] + recursion(i, W - wt[i], N, wt, val);
    }
    return dp[i][W] = max(notpick, pick);
}

