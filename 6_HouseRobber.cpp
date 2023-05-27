#include<bits/stdc++.h>
using namespace std;

int recursion(int i, vector<int>& nums){
    if(i == 0){
        return nums[0];
    }
    if(i < 0){
        return 0;
    }
    int notpick = recursion(i - 1, nums);
    int pick = INT_MIN;
    if(i-2 >= 0){
        pick = nums[i] + recursion(i - 2, nums);
    }
    return max(pick, notpick);
}

int houserobber(int n, vector<int>& nums){
    if(nums.size()==1)  return nums[0];
    
    //Delete front
    int front = nums.front();
    nums.erase(nums.begin());
    int exceptfront = recursion(n, nums);
    
    //Add front delete back
    nums.insert(nums.begin(),front);
    nums.pop_back();
    
    int exceptback = recursion(n, nums);
    
    return max(exceptfront, exceptback);
}