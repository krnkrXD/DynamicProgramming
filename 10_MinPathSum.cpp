#include <bits/stdc++.h>
using namespace std;

int recursion(int i, int j, int n, int m, vector<vector<int>> grid){
    if(i < 0 && j < 0) return 0;
    if(i == 0 && j == 0) return grid[i][j];

    int up = recursion(i - 1, j, n, m, grid);
    int left = recursion(i, j - 1, n, m, grid);
    return grid[i][j] + min(up, left);
}

int memo(int i, int j, int n, int m, vector<vector<int>> grid, vector<vector<int>>& dp){
    if(i < 0 && j < 0) return 0;
    if(i == 0 && j == 0) return grid[i][j];

    if(dp[i][j] != -1) return dp[i][j];

    int up = memo(i - 1, j, n, m, grid,dp);
    int left = memo(i, j - 1, n, m, grid,dp);
    return dp[i][j] = grid[i][j] + min(up, left);
}

int dp(int n, int m, vector<vector<int>> grid){
    vector<vector<int>> dp(n, vector<int>(m, -1));
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if (i == 0 && j == 0){
                dp[i][j] = grid[i][j];
            }
            else{
                int up = dp[i - 1][j];
                int left = dp[i][j - 1];
                dp[i][j] = min(up, left) + grid[i][j];
            }
        }
    }
    return dp[n - 1][m - 1];
}

int spaceoptimize(int n, int m, vector<vector<int>> grid){
    vector<int> prev(m);
    for (int i = 0; i < n; i++){
        vector<int> curr(m);
        for (int j = 0; j < m; j++){
            if (i == 0 && j == 0){
                curr[j] = grid[i][j];
            }
            else{
                int up = prev[j];
                int left = curr[j - 1];
                curr[j] = min(up, left) + grid[i][j];
            }
        }
    }
    return prev[m - 1];
}