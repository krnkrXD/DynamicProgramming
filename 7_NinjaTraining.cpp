#include<bits/stdc++.h>
using namespace std;
int recursion(int day, int prevtask, vector<vector<int>>& task){
    int n = task.size();
    if(day == n){
        int maxPtsTask = INT_MIN;
        for (int i = 0; i < 2; i++){
            if(i != prevtask){
                maxPtsTask = max(maxPtsTask, task[day][i]);
            }
        }
        return maxPtsTask;
    }
    int maxPtsTask = INT_MIN;
    for (int i = 0; i <= 2; i++){
        if(i != prevtask){
            maxPtsTask = max(maxPtsTask, recursion(day + 1, i, task));
        }
    }
    return maxPtsTask;
}
// recursion(0, -1, task);

int memo(int day, int prevtask, vector<vector<int>>& task, vector<vector<int>>& dp){
    int n = task.size();
    if(day == n){
        int maxPtsTask = INT_MIN;
        for (int i = 0; i <= 2; i++){
            if(i != prevtask){
                maxPtsTask = max(maxPtsTask, task[day][i]);
            }
        }
        return maxPtsTask;
    }
    
    if(dp[day][prevtask] != -1) return dp[day][prevtask];

    int maxPtsTask = INT_MIN;
    for (int i = 0; i <= 2; i++){
        if(i != prevtask){
            maxPtsTask = max(maxPtsTask, recursion(day + 1, i, task));
        }
    }
    return dp[day][prevtask] = maxPtsTask;
}
// vector<vector<int>> dp(n, vector<int>(3,-1));
// recursion(0, -1, task, dp);

int dp(vector<vector<int>>& tasks){
    int n = tasks.size();
    vector<vector<int>> dp(n, vector<int>(3, -1));
    for (int j = 0; j < 3; j++){
        dp[0][j] = tasks[0][j];
    }

    for (int day = 1; day < n; day++){
        for (int prevtask = 0; prevtask < 3; prevtask++){
            int maxpts = INT_MIN;
            for (int currtask = 0; currtask < 3; currtask++){
                if(currtask != prevtask){
                    maxpts = max(maxpts, dp[day - 1][prevtask] + tasks[day][currtask]);
                }
            }
            dp[day][]
        }
    }
}