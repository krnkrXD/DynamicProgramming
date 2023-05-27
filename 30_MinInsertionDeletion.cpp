#include <bits/stdc++.h>
using namespace std;

// minimum insetion/deletion operations to convert s1 to s2
// deletion = n - lcs()
// insertion = m - lcs()
// ans = n + m - 2*lcs()

// abcd -> anc -> ans = 3
// lcs = 2
// ans = 4 + 3 - 2*2 = 3

int minInsertionDeletion(string str1, string str2){
    int n = str1.size();
    int m = str2.size();
    
    int k = lcs(str1,str2);
    return (n-k)+(m-k);
}
int lcs(string s1, string s2) {
    int n=s1.size();
    int m=s2.size();

    vector<int> prev(m+1,0), cur(m+1,0);
    
    // Base Case is covered as we have initialized the prev and cur to 0.
    for(int ind1=1;ind1<=n;ind1++){
        for(int ind2=1;ind2<=m;ind2++){
            if(s1[ind1-1]==s2[ind2-1])
                cur[ind2] = 1 + prev[ind2-1];
            else
                cur[ind2] = 0 + max(prev[ind2],cur[ind2-1]);
        }
        prev = cur;
    }
    
    return prev[m];
}

