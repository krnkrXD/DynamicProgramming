#include<bits/stdc++.h>
using namespace std;
// A subset/subsequence is a contiguous or non-contiguous part of an array, where elements appear in the same order as the original array.
// Partition : sum(arr1) = sum(arr2) and sum(arr1) + sum(arr2) = sum(arr)
// which means sum(arr1) = sum(arr)/2;

int subsetsumtarget(vector<int> arr, int n, int target){
    int n = arr.size();
    vector<bool> prev(target + 1, false);

    prev[0] = true;    // target == 0
    if(arr[0] <= target){
        prev[arr[0]] = true;
    }

    for (int i = 1; i < n; i++){
        vector<bool> curr(target + 1, false);
        curr[0] = true;
        for (int tar = 1; tar <= target; tar++){
            // possible stuffs
            int pick = false;
            if(arr[i] <= tar){
                pick = prev[tar - arr[i]];
            }
            int notpick = prev[tar];
            curr[tar] = pick || notpick;
        }
        prev = curr;
    }

    return prev[target];
}

int solve(vector<int> arr, int n){
    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += arr[i];

    return subsetsumtarget(arr, n-1, sum/2);
}