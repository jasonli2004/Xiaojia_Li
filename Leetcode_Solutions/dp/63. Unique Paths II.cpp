class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<int> dp(n, 1);
        for (int i = 0; i < n; i++){
            if (obstacleGrid[0][i] == 1){
                for (int j = i; j < n; j++){
                    dp[j] = 0;
                }
                break;
            }
        }
        for (int i = 1; i < m; i++){
            for (int j = 0; j < n; j++){
                if (j == 0){
                    if (dp[0] == 0 || obstacleGrid[i][0] == 1){
                        dp[0] = 0;
                    }
                }
                else{
                    if (obstacleGrid[i][j] == 1){
                        dp[j] = 0;
                    }
                    else{
                        dp[j] = dp[j] + dp[j - 1];
                    }
                }
            }
        }
        return dp[n - 1];
    }
};