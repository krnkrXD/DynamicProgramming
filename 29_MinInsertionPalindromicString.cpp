
#include <bits/stdc++.h>
using namespace std;
// minimum insertion to make string palindromic
// n - longest palindromic subsequence
// lps(lcs(s,rev(s)))

// abcaa
// lcs(abcaa, aacba) = 3
// lps(lcs) = 3
// ans = 5 - 3 = 2
int lcs(string s1, string s2) {
    int n=s1.size(), m=s2.size();
    
    vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
    for(int i=0;i<=n;i++){
        dp[i][0] = 0;
    }
    for(int i=0;i<=m;i++){
        dp[0][i] = 0;
    }
    
    for(int ind1=1;ind1<=n;ind1++){
        for(int ind2=1;ind2<=m;ind2++){
            if(s1[ind1-1]==s2[ind2-1])
                dp[ind1][ind2] = 1 + dp[ind1-1][ind2-1];
            else
                dp[ind1][ind2] = 0 + max(dp[ind1-1][ind2],dp[ind1][ind2-1]);
        }
    }
    return dp[n][m];
}

int longestPalindromeSubsequence(string s){
    string s1 = s;
    reverse(s.begin(),s.end());
    string s2 = s;
    return lcs(s1,s2);
}

int minInsertion(string s){
    int n = s.size();
    int k = longestPalindromeSubsequence(s);
    return n - k;
}

// Time Complexity: O(N*N)
// Reason: There are two nested loops
// Space Complexity: O(N*N)
// Reason: We are using an external array of size (N*N). Stack Space is eliminated.