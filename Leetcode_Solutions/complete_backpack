//normal version
int knapsack(vector<int> weights, vector<int> values, int N, int W) {
    vector<vector<int>> dp(N+1, vector<int>(W+1, 0));
    for (int i = 1; i <= N; i++){
        int v = values[i-1];
        int w = weights[i-1];
        for (int j = 1; j <= W; j++){
            if (j >= w){
                dp[i][j] = max(dp[i-1][j], dp[i][j-w]+v);
            }
            else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    return dp[N][W];
}

//space-efficient version

int knapsack(vector<int> weights, vector<int> values, int N, int W) {
    vector<int> dp(W+1, 0);
    for (int i = 1; i <= N; i++){
        int v = values[i-1];
        int w = weights[i-1];
        for (int j = w; j <= W; j--){
            dp[i][j] = max(dp[j], dp[j-w]+v);
        }
    }
    return dp[N][W];
}