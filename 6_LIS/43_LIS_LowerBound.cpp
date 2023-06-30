#include <bits/stdc++.h>
using namespace std;

/*
Now, as we have understood the entire intuition of the algorithm we will summarize the approach:
Initialize a temp array.
Push the first element of the array to temp.
Iterate over the next elements.
In every iteration, if arr[i] is greater than the last element of the temp array simply push it to the temp array.
Else, just find the lower_bound index of that element in the temp array (say ind). THen simply initialize temp[ind] = arr[i] (// replacement step).
Maintain a len variable to calculate the length of the temp array in the iteration itself.*/
int longestIncreasingSubsequence(int arr[], int n){    
    vector<int> temp;
    temp.push_back(arr[0]); 
    int len = 1;
    for(int i=1; i<n; i++){
        if(arr[i]>temp.back()){
           // arr[i] > the last element of temp array 
           temp.push_back(arr[i]);
           len++; 
        } 
        else{
	        // replacement step
            int ind = lower_bound(temp.begin(),temp.end(),arr[i]) - temp.begin();
            temp[ind] = arr[i];
        }  
    } 
    return len;
}