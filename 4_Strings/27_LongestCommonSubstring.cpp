#include<bits/stdc++.h>
using namespace std;


// s1 = abdejcu
// s2 = jgbdejuit
// Ans= bdej -> Largest Common Substring
int lcs(string &s1, string &s2){
    int n = s1.size();
    int m = s2.size();
    
    vector<vector<int>> dp(n+1,vector<int>(m+1,0));
    int ans = 0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(s1[i-1]==s2[j-1]){
                int val = 1 + dp[i-1][j-1];
                dp[i][j] = val;
                
                ans = max(ans,val); // maximum # of common
            }
            else
                dp[i][j] = 0;
        }
    }
    return ans;
}

int lcs(string &s1, string &s2){
    int n = s1.size(), m = s2.size();

    vector<int> prev(m + 1, 0);
    int ans = 0;
    for(int i=1;i<=n;i++){
        vector<int> curr(m + 1, 0);
        for(int j=1;j<=m;j++){
            if(s1[i-1]==s2[j-1]){
                int val = 1 + prev[j-1];
                curr[j] = val;
                
                ans = max(ans,val); // maximum # of common
            }
            else
                curr[j] = 0;
        }
        prev = curr;
    }
    return ans;
}