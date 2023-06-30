#include<bits/stdc++.h>
using namespace std;

int util_recursion(int ind1, int ind2, string s1, string s2){
    if(ind1 < 0) return 0;
    if(ind2 < 0) return 1;

    if(s1[ind1] == s2[ind2])
        return util_recursion(ind1 - 1, ind2 - 1, s1, s2) +
               util_recursion(ind1 - 1, ind2, s1, s2);
    else
        return util_recursion(ind1 - 1, ind2 - 1, s1, s2);
}
int distinctsubsequences(string s1, string s2){
    int n = s1.length(), m = s2.length();
    return util_recursion(n - 1, m - 1, s1, s2);
}

int util_memo(int ind1, int ind2, string s1, string s2, vector<vector<int>>& dp){
    if(ind1 < 0) return 0;
    if(ind2 < 0) return 1;

    if(dp[ind1][ind2] != -1) return dp[ind1][ind2];

    if(s1[ind1] == s2[ind2])
        return  dp[ind1][ind2] =
                util_recursion(ind1 - 1, ind2 - 1, s1, s2) +
                util_recursion(ind1 - 1, ind2, s1, s2);
    else
        return dp[ind1][ind2] = util_recursion(ind1 - 1, ind2 - 1, s1, s2);
}
int distinctsubsequences(string s1, string s2){
    int n = s1.length(), m = s2.length();
    vector<vector<int>> dp(n, vector<int>(m, -1));
    return util_memo(n - 1, m - 1, s1, s2, dp);
}

// ind1 -> -1 to n-1
// ind2 -> -1 to m-1
// so, push one step forward.
// ind1 -> 0 to n    ind2 -> 0 to m
int tabulation(string s1, string s2){
    int n = s1.length(), m = s2.length();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
}