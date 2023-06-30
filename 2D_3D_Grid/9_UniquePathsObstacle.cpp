#include <bits/stdc++.h>
using namespace std;

int recursion(int i, int j, int n, int m, vector<vector<int>> mat){
    if(i < 0 && j < 0)
        return 0;
    if(i > 0 && j > 0 && mat[i][j] == -1)
        return 0;
    if(i == 0 && j == 0)
        return 1;

    int up = recursion(i - 1, j, n, m, mat);
    int left = recursion(i, j - 1, n, m, mat);
    return up + left;
}

int memo(int i, int j, int n, int m, vector<vector<int>> mat, vector<vector<int>> dp){
    if(i < 0 && j < 0)
        return 0;
    if(i > 0 && j > 0 && mat[i][j] == -1)
        return 0;
    if(i == 0 && j == 0)
        return 1;

    if(dp[i][j] != -1) return dp[i][j];

    int up = memo(i - 1, j, n, m, mat, dp);
    int left = memo(i, j - 1, n, m, mat, dp);
    return dp[i][j] = up + left;
}
// dp[n][m] = {-1};
// memo(n - 1, m - 1, n, m, mat, dp);

/*Time Complexity: O(N*M)
Reason: At max, there will be N*M calls of recursion.
Space Complexity: O((M-1)+(N-1)) + O(N*M)
Reason: We are using a recursion stack space:O((M-1)+(N-1)), here (M-1)+(N-1) is the path length and an external DP Array of size ‘N*M’.*/



int dp(int n, int m, vector<vector<int>> mat){
    vector<vector<int>> dp(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if(i > 0 && j > 0 && mat[i][j] == -1)
                dp[i][j] = 0;
            else if(i == 0 && j == 0)
                dp[i][j] = 1;
            else{
                int up = dp[i - 1][j];
                int left = dp[i][j - 1];
                dp[i][j] = up + left;
            }
        }
    }
    return dp[n - 1][m - 1];
}

// Time Complexity: O(N*M)
// Space Complexity: O(N*M)


int spaceoptimize(int n, int m, vector<vector<int>> mat){
    vector<vector<int>> dp(n, vector<int>(m, 0));
    vector<int> prev(m);
    for (int i = 0; i < n; i++){
        vector<int> curr(m);    
        for (int j = 0; j < m; j++){
            if(i > 0 && j > 0 && mat[i][j] == -1)
                curr[j] = 0;
            else if(i == 0 && j == 0)
                curr[j] = 1;
            else{
                int up = prev[j];
                int left = curr[j - 1];
                curr[j] = up + left;
            }
        }
    }
    return prev[m - 1];
}
// Time Complexity: O(N*M)
// Space Complexity: O(M)