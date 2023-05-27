#include <bits/stdc++.h>
using namespace std;
// alice - top left
// bob - top right
// bottom, diag left, diag right

// both at same cell = only one can get

int recursion (int i, int j1, int j2, int n, int m, vector<vector<int>>& grid){
    if(i == n-1){
        if(j1 == j2){
            return grid[i][j1];
        }
        else{
            return grid[i][j1] + grid[i][j2];
        }
    }

    int max_choco = INT_MIN;
    for (int d1 = -1; d1 <= 1; d1++){
        for (int d2 = -1; d2 <= 1; d2++){
            if(j1 == j2){
                max_choco = max(max_choco, recursion(i, j1 + d1, j2 + d2, n, m, grid))
                            + grid[i][j1];
            }
            else{
                max_choco = max(max_choco, recursion(i, j1 + d1, j2 + d2, n, m, grid))+
                            + grid[i][j1] + grid[i][j2];
            }
        }
    }
    return max_choco;
}

// vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(m, -1)));
int recursion (int i, int j1, int j2, int n, int m, vector<vector<int>>& grid, vector<vector<vector<int>>>& dp){
    if(i == n-1){
        if(j1 == j2){
            return grid[i][j1];
        }
        else{
            return grid[i][j1] + grid[i][j2];
        }
    }

    if(dp[i][j1][j2] != -1) {
        return dp[i][j1][j2];
    }

    int max_choco = INT_MIN;
    for (int d1 = -1; d1 <= 1; d1++){
        for (int d2 = -1; d2 <= 1; d2++){
            if(j1 == j2){
                max_choco = max(max_choco, recursion(i + 1, j1 + d1, j2 + d2, n, m, grid))
                            + grid[i][j1];
            }
            else{
                max_choco = max(max_choco, recursion(i + 1, j1 + d1, j2 + d2, n, m, grid))+
                            + grid[i][j1] + grid[i][j2];
            }
        }
    }
    return dp[i][j1][j2] = max_choco;
}

int dp(int n, int m, vector<vector<int>>& grid){
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(m, -1)));

    for (int j1 = 0; j1 < m; j1++){
        for (int j2 = 0; j2 < m; j2++){
            if(j1==j2){
                dp[n - 1][j1][j2] = grid[n - 1][j2];
            }
            else{
                dp[n - 1][j1][j2] = grid[n - 1][j1] + grid[n - 1][j2];
            }
        }
    }

    for (int i = n - 2; i >= 0; i--){
        for (int j1 = 0; j1 < m; j1++){
            for (int j2 = 0; j2 < m; j2++){
                int max_choco = INT_MIN;
                for (int d1 = -1; d1 <= 1; d1++){
                    for (int d2 = -1; d2 <= 1; d2++){
                        if(j1 == j2){
                            max_choco = max(max_choco, dp[i+1][j1 + d1][j2 + d2])
                                        + grid[i][j1];
                        }
                        else{
                            max_choco = max(max_choco, dp[i+1][j1 + d1][j2 + d2])+
                                        + grid[i][j1] + grid[i][j2];
                        }
                    }
                }
                dp[i][j1][j2] = max_choco;
            }
        }   
    }

    return dp[0][0][m - 1];
}