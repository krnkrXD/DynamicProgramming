int recursion(int i, vector<int> energy, int k){
    if(i == 0)
        return 0;

    int minenergy = INT_MAX;
    for (int i = 0; i < k; i++){
        if(i-k >= 0)
            minenergy = min(recursion(i - k, energy, k), minenergy);
    }
    
    return minenergy;
}

int memo(int i, vector<int> energy, int k, vector<int>& dp){
    if(i == 0) return 0;

    if(dp[i] != -1) return dp[i];

    int minenergy = INT_MAX;
    for (int i = 0; i < k; i++){
        if(i-k >= 0)
            minenergy = min(recursion(i - k, energy, k), minenergy);
    }
    
    return dp[i] = minenergy;
}

int tablulation(int n, vector<int> energy){
    vector<int> dp(n, 0);
    dp[0] = 0;
    for (int i = 1; i < n; i++){
        int left = dp[i - 1] + abs(energy[i] - energy[i - 1]);
        int right = INT_MAX;
        if(i-2>=0) right = dp[i-2] + abs(energy[i] - energy[i - 2]);

        dp[i] = min(left, right);
    }

    return dp[n-1];
}

int spaceoptimization(int n, vector<int> energy){
    int prevprev = 1, prev, curr;
    for (int i = 2; i <= n; i++){
        int left = prev + abs(energy[i] - energy[i - 1]);
        int right = INT_MAX;
        if(i-2>=0) right = prevprev + abs(energy[i] - energy[i - 2]);

        curr = min(left, right);
        prevprev = prev;
        prev = curr;
    }
    return curr;
}