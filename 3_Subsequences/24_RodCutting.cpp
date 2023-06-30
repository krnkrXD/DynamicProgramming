#include <bits/stdc++.h>
using namespace std;

// ind = [0,1,2,3,4]
// val = [2,5,4,5,6]
//rodL = [1,2,3,4,5]   rodLength = ind + 1

int cutRodUtil_recursion(vector<int>& price, int ind, int N, vector<vector<int>>& dp){
    if(ind == 0){
        // rodlength = 1, price = (N/rodlength) * price[0]
        return N * price[0];
    }
    
    if(dp[ind][N]!=-1) return dp[ind][N];

    int notTaken = 0 + cutRodUtil_recursion(price, ind - 1, N, dp);
    int taken = INT_MIN, rodLength = ind + 1;
    if(rodLength <= N) // lands on same index(infinite supply)
        taken = price[ind] + cutRodUtil_recursion(price, ind, N - rodLength, dp);
    
    return dp[ind][N] = max(notTaken, taken);
}
int cutRod(vector<int>& price,int N) {
    vector<vector<int>> dp(N, vector<int>(N + 1, -1));
    return cutRodUtil_recursion(price, N - 1, N, dp);
}


int tabulation(vector<int>& price, int N){
    vector<vector<int>> dp(N, vector<int>(N + 1, 0));
    for (int i = 0; i < N + 1; i++){
        dp[0][i] = i * price[0];
    }
    for (int i = 1; i < N; i++){
        for (int j = 0; j < N + 1; j++){
            int notTaken = 0 + dp[i - 1][j];
            int taken = INT_MIN, rodLength = i + 1;
            if(rodLength <= j) // lands on same index(infinite supply)
                taken = price[i] + dp[i][j - rodLength];
            
            dp[i][j] = max(notTaken, taken);
        }
    }
    return dp[N - 1][N];
}

// only uses prev values of same row and same column of prev row.
int spaceoptimize(vector<int>& price, int N){
    vector<int> prev(N+1, 0);
    for (int i = 0; i < N + 1; i++){
        prev[i] = i * price[0];
    }

    for (int i = 1; i < N; i++){
        vector<int> curr(N + 1, 0);
        for (int j = 0; j < N + 1; j++){
            int nottaken = prev[j];
            int taken = INT_MIN, rodlength = i + 1;
            if(rodlength <= j){
                taken = price[i] + prev[j - rodlength];
            }
            prev[j] = max(nottaken, taken);
        }
    }
    return prev[N];
}