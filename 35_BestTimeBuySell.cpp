#include<bits/stdc++.h>
using namespace std;

// Best time to buy/sell stock
// maximize the profit, arr[] where ith day
int maximumProfit(vector<int> &prices, int n){
	int maxProfit = 0;
	int mini = prices[0];

    for (int i = 1; i < n; i++){
        int curProfit = prices[i] - mini;
        maxProfit = max(maxProfit, curProfit);
        mini = min(mini, prices[i]);
    }
    return maxProfit;
}