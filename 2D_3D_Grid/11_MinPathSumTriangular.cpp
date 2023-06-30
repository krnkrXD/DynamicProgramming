#include <bits/stdc++.h>
using namespace std;
// Fixed Starting and Ending Point
// 1
// 2 3
// 3 6 7
// 8 9 6 10
int recursion(int i, int j, int n, int m, vector<vector<int>> grid){
    if(i == n - 1 ){
        return grid[i][j];
    }
    
    int down = recursion(i + 1, j, n, m, grid);
    int diag = recursion(i + 1, j + 1, n, m, grid);
    return grid[i][j] + min(down, diag);
}

int memo(int i, int j, int n, int m, vector<vector<int>> grid, vector<vector<int>>& dp){
    if(i == n - 1 ){
        return grid[i][j];
    }
    
    if(dp[i][j] != -1) return dp[i][j];

    int down = recursion(i + 1, j, n, m, grid);
    int diag = recursion(i + 1, j + 1, n, m, grid);
    return dp[i][j] = grid[i][j] + min(down, diag);
}
// Time Complexity: O(N*M)
// Space Complexity: O(N*M) + O(N)


int dp(int n, int m, vector<vector<int>>& grid){
    vector<vector<int>> dp(n, vector<int>(m, 0));
    
    for (int i = n - 1; i >= 0; i--){
        for (int j = 0; j <= i; j++){
            if(i == n-1){
                dp[i][j] = grid[i][j];
            }
            else{
                int down = dp[i + 1][j];
                int diag = dp[i + 1][j + 1];
                dp[i][j] = min(down, diag) + grid[i][j];
            }
        }
    }
    return dp[0][0];
}
// Time Complexity: O(N*M)
// Space Complexity: O(N*M)


int spaceoptimize(int n, int m, vector<vector<int>>& grid){
    vector<int> next(m);
    for (int i = n - 1; i >= 0; i--){
        vector<int> curr(i+1);
        for (int j = 0; j <= i; j++){
            if(i == n-1){
                curr[j] = grid[i][j];
            }
            else{
                int down = next[j];
                int diag = next[j + 1];
                curr[j] = min(down, diag) + grid[i][j];
            }
        }
    }
    return next[0];
}

// Time Complexity: O(N*M)
// Space Complexity: O(M)