#include <bits/stdc++.h>
using namespace std;

// bbabcbcab
// bacbcbabb
// b11bcb11b
// bbcbb

// LCS(str, rev(str));
int LPS(string s){
    string s1 = s;
    reverse(s.begin(), s.end());
    string s2 = s;
    return lcs_spaceoptimize(s1, s2);
}

/*----------------------------------------------------------------------------------------*/
int lcsUtil_recursion(string& s1, string& s2, int ind1, int ind2,  vector<vector<int>>& dp){
    // out of bound 
    if(ind1<0 || ind2<0) return 0;
        
    if(dp[ind1][ind2]!=-1) return dp[ind1][ind2];

    if(s1[ind1] == s2[ind2]) // both char are same, go to next index.
        return dp[ind1][ind2] = 1 + lcsUtil_recursion(s1,s2,ind1-1,ind2-1,dp);
    
    else // go next index of s1 then s2
        return dp[ind1][ind2] = 0 + max(lcsUtil_recursion(s1,s2,ind1,ind2-1,dp),lcsUtil_recursion(s1,s2,ind1-1,ind2,dp));
}
int lcs(string s1, string s2) {
    int n=s1.size(), m=s2.size();

    vector<vector<int>> dp(n,vector<int>(m,-1));
    return lcsUtil_recursion(s1,s2,n-1,m-1,dp);
}

int lcs_tabulation(string s1, string s2){
    int n = s1.length(), m = s2.length();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    for (int ind1 = 1; ind1 <= n; ind1++){
        for (int ind2 = 1; ind2 <= m; ind2 ++){
            if(s1[ind1-1] == s2[ind2-1]) // both char are same, go to next index.
                return dp[ind1][ind2] = 1 + dp[ind1-1][ind2-1];
            else // go next index of s1 then s2
                return dp[ind1][ind2] = 0 + max(dp[ind1][ind2-1],dp[ind1-1][ind2]);
        }
    }
    return dp[n][m];
}

int lcs_spaceoptimize(string s1, string s2){
    int n = s1.length(), m = s2.length();
    vector<int> prev(m + 1, 0);
    for (int ind1 = 1; ind1 <= n; ind1++){
        vector<int> curr(m+1, 0);
        for (int ind2 = 1; ind2 <= m; ind2 ++){
            if(s1[ind1-1] == s2[ind2-1]) // both char are same, go to next index.
                curr[ind2] = 1 + prev[ind2-1];
            else // go next index of s1 then s2
                curr[ind2] = 0 + max(curr[ind2-1],prev[ind2]);
        }
        prev = curr;
    }
    return prev[m];
}