#include<bits/stdc++.h>
using namespace std;
int recursive(int n){
    if(n == 0){
        return 0;
    }
    if(n == 1){
        return 1;
    }
    
    int left = recursive(n - 1);   // take one step down
    int right = recursive(n - 2);   // take two step down

    return left + right;
}

int memo(int n, int dp[]){
    if(n == 0){
        return 0;
    }
    if(n == 1){
        return 1;
    }
    
    if(dp[n] != -1) return dp[n];   // if value is present

    int left = recursive(n - 1);    // take one step down
    int right = recursive(n - 2);   // take two step down

    return dp[n] = left + right;    // store the value for later
}

int tabulation(int n){
    vector<int> dp(n + 1, 0);
    dp[0] = 0;
    dp[1] = 1;
    for (int i = 2; i <= n; i++){
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[n];
}

int spaceoptimize(int n){
    int prevprev = 0, prev = 1, curr;
    for (int i = 2; i <= n; i++){
        curr = prevprev + prev;
        prevprev = prev;
        prev = curr;
    }
    return curr;
}