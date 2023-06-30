#include<bits/stdc++.h>
using namespace std;

// return 1+f(i-1,j)    // Insertion of character.
// return 1+f(i,j-1)    // Deletion of character.
// return 1+f(i-1,j-1)  // Replacement of character.

int editDistanceUtil(string& S1, string& S2, int i, int j, vector<vector<int>>& dp){
    if(i<0)
        return j+1;
    if(j<0)
        return i+1;
        
    if(dp[i][j]!=-1) return dp[i][j];
        
    if(S1[i]==S2[j])
        return dp[i][j] =  0+editDistanceUtil(S1,S2,i-1,j-1,dp);
    
    // Minimum of three choices
    else
        return dp[i][j] = 1 + 
        min(editDistanceUtil(S1, S2, i - 1, j - 1, dp),
        min(editDistanceUtil(S1, S2, i - 1, j, dp), 
        editDistanceUtil(S1, S2, i, j - 1, dp)));
}
int editDistance(string& S1, string& S2){
    int n = S1.size();
    int m = S2.size();
    vector<vector<int>> dp(n,vector<int>(m,-1));
    return editDistanceUtil(S1,S2,n-1,m-1,dp);
}
// Time Complexity: O(N*M)
// Reason: There are N*M states therefore at max ‘N*M’ new problems will be solved.
// Space Complexity: O(N*M) + O(N+M)
// Reason: We are using a recursion stack space(O(N+M)) and a 2D array ( O(N*M)).




int tabulation(string s1, string s2){
    int n = s1.size(), m = s2.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    for (int i = 0; i <= n; i++){
        dp[i][0] = i;
    }
    for (int j = 0; j <= m; j++){
        dp[0][j] = j;
    }

    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            if(s1[i-1] == s2[j-1])
                dp[i][j] =  dp[i-1][j-1];
            
            // Minimum of three choices
            else
                dp[i][j] = 1 + min(dp[i - 1][j - 1],min(dp[i - 1][j], dp[i][j - 1]));
        }
    }
    return dp[n][m];
}
// Time Complexity: O(N*M)
// Reason: There are two nested loops
// Space Complexity: O(N*M)
// Reason: We are using an external array of size ‘N*M’. Stack Space is eliminated.




int spaceoptimize(string s1, string s2){
    int n = s1.size(), m = s2.size();
    vector<int> prev(m + 1, 0);
    vector<int> curr(m + 1, 0);
    for (int j = 0; j <= m; j++){
        prev[j] = j;
    }
    // for (int i = 0; i <= n; i++){
    //     dp[i][0] = i;
    // }

    for (int i = 1; i <= n; i++){
        curr[0] = i;
        for (int j = 1; j <= m; j++){
            if(s1[i-1] == s2[j-1])
                curr[j] =  prev[j-1];
            
            // Minimum of three choices
            else
                curr[j] = 1 + min(prev[j - 1],min(prev[j], curr[j - 1]));
        }
        prev = curr;
    }
    return prev[m];
}
// Time Complexity: O(N*M)
// Reason: There are two nested loops.
// Space Complexity: O(M)
// Reason: We are using an external array of size ‘M+1’ to store two rows.