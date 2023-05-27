#include <bits/stdc++.h>
using namespace std;
// Variable Starting and Ending Point
// bottom, diag left, diag right

int recursion(int i, int j, int n, int m, vector<vector<int>>& grid){
    // base case
    if(i == 0){
        return grid[i][j];
    }

    // bottom, diag left, diag right
    int bottom = INT_MAX, diag_left = INT_MAX, diag_right = INT_MAX;
    if(i - 1 < n){
        bottom = recursion(i - 1, j, n, m, grid);
    }
    if(i - 1 < n && j - 1 >= 0){
        diag_left = recursion(i - 1, j - 1, n, m, grid);
    }
    if(i - 1 < n && j - 1 < m){
        diag_right = recursion(i - 1, j - 1, n, m, grid);
    }
    return min(bottom, min(diag_left, diag_right)) + grid[i][j];
}
// Time Complexity: O(N*M)
// Space Complexity: O(N) - O(N*M)

// vector<vector<int>> dp(n, vector<int>(m, -1));
int memo(int i, int j, int n, int m, vector<vector<int>>& grid, vector<vector<int>>& dp){
    // base case
    if(i == 0){
        return grid[i][j];
    }

    // if the answer is already solved,
    if(dp[i][j] != -1) return dp[i][j];

    // bottom, diag left, diag right
    int bottom = INT_MAX, diag_left = INT_MAX, diag_right = INT_MAX;
    if(i - 1 < n){
        bottom = memo(i - 1, j, n, m, grid, dp);
    }
    if(i - 1 < n && j - 1 >= 0){
        diag_left = memo(i - 1, j - 1, n, m, grid,dp);
    }
    if(i - 1 < n && j - 1 < m){
        diag_right = memo(i - 1, j - 1, n, m, grid, dp);
    }
    return min(bottom, min(diag_left, diag_right)) + grid[i][j];
}
// Time Complexity: O(N*M)
// Space Complexity: O(N) - O(N*M)

int dp(int n, int m, vector<vector<int>>& grid){
    vector<vector<int>> dp(n, vector<int>(m, 0));

    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if(i == 0){
                dp[i][j] = grid[i][j];
            }
            else{
                int bottom = INT_MAX, diag_left = INT_MAX, diag_right = INT_MAX;
                if(i - 1 < n){
                    bottom = memo(i - 1, j, n, m, grid, dp);
                }
                if(i - 1 < n && j - 1 >= 0){
                    diag_left = memo(i - 1, j - 1, n, m, grid,dp);
                }
                if(i - 1 < n && j - 1 < m){
                    diag_right = memo(i - 1, j + 1, n, m, grid, dp);
                }
                dp[i][j] = min(bottom, min(diag_left, diag_right)) + grid[i][j];
            }
        }
    }
    int mini = INT_MAX;
    for(int i : dp[n-1]){
        mini = min(mini, i);
    }
    return mini;
}
