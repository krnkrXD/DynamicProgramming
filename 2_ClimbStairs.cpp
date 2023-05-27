int recursion(int i){
    if(i == 0 or i == 1) {
        return 1;
    }

    return recursion(i - 1) + recursion(i - 2);
}

int memo(int i, vector<int>& dp){
    if(i == 0 or i == 1)
        return 1;
    
    if(dp[i] != -1)
        return dp[i];

    return dp[i] = memo(i - 1, dp) + memo(i - 2, dp);
}

int tabulation(int n){
    vector<int> dp(n+1, 0);
    dp[0] = dp[1] = 1;
    for (int i = 2; i <= n; i++){
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[n];
}

int spaceoptimization(int n){
    int prevprev = 1, prev = 1, curr = 0;
    for (int i = 2; i <= n; i++){
        curr = prevprev + prev;
        prevprev = prev;
        curr = prev;
    }
    return prev;
}
