#include<bits/stdc++.h>
using namespace std;

// same as Buy sell stock 3 but here instead of 2 transaction use k.
int solve(int i, int buy, int cap, vector<int>& prices, vector<vector<vector<int>>>& dp){
    // base case
    if(cap == 0 or i == prices.size()){
        return 0;
    }
    if(dp[i][buy][cap] != -1) return dp[i][buy][cap];
    int option1, option2;
    // we can buy something
    if(buy == 0){
        // no transaction
        option1 = solve(i + 1, buy, cap, prices, dp);
        // buy the stock on ith day
        option2 = -prices[i] + solve(i + 1, !buy, cap, prices, dp);
    }   
    // we can sell stock
    if(buy == 1){
        // no transaction
        option1 = solve(i + 1, buy, cap, prices, dp);
        // sell the stock on ith day
        option2 = prices[i] + solve(i + 1, !buy, cap - 1, prices, dp);
    }
    return dp[i][buy][cap] = max(option1, option2);
}
int maxProfit(vector<int>& prices, int k){
    int n = prices.size();
    // buy == 0, means buy the stock. and vice versa.
    vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2, vector<int>(k+1, -1)));
    return solve(0, 0, 2, prices, dp);
}
// Time complexity :  O(N*2*2)
// Space Complexity : O(N) + O(N*2*2)

int maxProfit(vector<int>& prices, int k){
    int n = prices.size();
    vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2, vector<int>(k+1, -1)));

    for (int i = n-1; i >= 0; i--){
        for (int buy = 0; buy <= 1; buy++){
            for (int cap = 1; cap <= k; cap++){
                int option1, option2;
                // we can buy something
                if(buy == 0){
                    // no transaction
                    option1 = dp[i + 1][buy][cap];
                    // buy the stock on ith day
                    option2 = -prices[i] + dp[i + 1][!buy][cap];
                }   
                // we can sell stock
                if(buy == 1){
                    // no transaction
                    option1 = dp[i + 1][buy][cap];
                    // sell the stock on ith day
                    option2 = prices[i] + dp[i + 1][!buy][cap - 1];
                }
                dp[i][buy][cap] = max(option1, option2);
            }
        }
    }
    return dp[0][0][k];
}