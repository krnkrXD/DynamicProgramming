#include<bits/stdc++.h>
using namespace std;

// Memoization
int solve(int i, int buy, vector<int>& prices, vector<vector<int>>& dp){
    if(i == prices.size()){
        return 0;
    }
    
    if(dp[i][buy] != -1) return dp[i][buy];
    
    int option1, option2;
    if(buy == 1){
        // no transaction
        option1 = solve(i+1, buy, prices, dp);
        // buy the stock
        option2 = -prices[i] + solve(i+1,!buy, prices, dp);
    }
    else if(buy == 0){
        // no transaction
        option1 = solve(i+1, buy, prices, dp);
        // sell the stock
        option2 = prices[i] + solve(i+1, !buy, prices, dp);
    }
    return dp[i][buy] = max(option1, option2);
}

int maxProfit(vector<int>& prices) {
    int n = prices.size();
    vector<vector<int>> dp(n, vector<int>(2,-1));
    return solve(0,1,prices,dp);
}

// Tabulation
int maxProfit(vector<int>& prices) {
    int n = prices.size();
    // i -> [0,n]
    vector<vector<int>> dp(n+1, vector<int>(2,-1));
    dp[n][0] = dp[n][1] = 0;
    for (int i = n - 1; i >= 0; i--){
        for (int buy = 1; buy >= 0; buy--){
            int option1, option2;
            if(buy == 1){
                // no transaction
                option1 = dp[i+1][buy];
                // buy the stock
                option2 = -prices[i] + dp[i+1][!buy];
            }
            else if(buy == 0){
                // no transaction
                option1 = dp[i+1][buy];
                // sell the stock
                option2 = prices[i] + dp[i+1][!buy];
            }
            dp[i][buy] = max(option1, option2);
        }
    }
    return dp[0][0];
}