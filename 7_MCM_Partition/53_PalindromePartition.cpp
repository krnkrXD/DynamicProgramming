#include <bits/stdc++.h>
using namespace std;
#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(int i, int j, string &s) {
    while (i < j) {
        if (s[i] != s[j]) return false;
        i++;
        j--;
    }
    return true;
}
int f(int i, int n, string &str) {
    //Base case:
    if (i == n) return 0;

    int minCost = INT_MAX;
    //string[i...j] and string[j+1...n]
    for (int j = i; j < n; j++) {
        if (isPalindrome(i, j, str)) {
            int cost = 1 + f(j + 1, n, str);
            minCost = min(minCost, cost);
        }
    }
    return minCost;
}
int palindromePartitioning(string str) {
    // Write your code here
    int n = str.size();
    return f(0, n, str) - 1;
}