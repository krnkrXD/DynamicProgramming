#include<bits/stdc++.h>
using namespace std;

// same as Buy sell stock 3 but here instead of 2 transaction use k.
int solve(int i, int buy, vector<int>& prices, vector<vector<int>>& dp){
    // base case
    if(i >= prices.size()){
        return 0;
    }
    if(dp[i][buy] != -1) return dp[i][buy];
    int option1, option2;
    // we can buy something
    if(buy == 0){
        // no transaction
        option1 = solve(i + 1, buy, prices, dp);
        // buy the stock on ith day
        option2 = -prices[i] + solve(i + 1, !buy, prices, dp);
    }   
    // we can sell stock
    if(buy == 1){
        // no transaction
        option1 = solve(i + 1, buy, prices, dp);
        // sell the stock on ith day
        option2 = prices[i] + solve(i + 2, !buy, prices, dp);
    }
    return dp[i][buy] = max(option1, option2);
}
int maxProfit(vector<int>& prices){
    int n = prices.size();
    // buy == 0, means buy the stock. and vice versa.
    vector<vector<int>> dp(n+1, vector<int>(2,-1));
    return solve(0, 0, prices, dp);
}

int maxProfit(vector<int>& prices){
    int n = prices.size();
    vector<vector<int>> dp(n + 2, vector<int>(2, 0));
    dp[n][0] = dp[n][1] = 0;
    for (int i = n - 1; i >= 0; i--){
        for (int buy = 0; buy <= 1; buy++){
            int option1, option2;
            // we can buy something
            if(buy == 0){
                // no transaction
                option1 = dp[i + 1][buy];
                // buy the stock on ith day
                option2 = -prices[i] + dp[i + 1][!buy];
            }   
            // we can sell stock
            if(buy == 1){
                // no transaction
                option1 = dp[i + 1][buy];
                // sell the stock on ith day
                option2 = prices[i] + dp[i + 2][!buy];
            }
            dp[i][buy] = max(option1, option2);
        }
    }
    return dp[0][0];
}