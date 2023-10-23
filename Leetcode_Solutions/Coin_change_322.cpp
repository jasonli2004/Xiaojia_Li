class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int len = coins.size();
        vector<int> dp(amount + 1, amount+1);
        dp[0] = 0;
        for (int i = 1; i <= len; i++){
            int w = coins[i-1];
            for (int j = w; j <= amount; j++){
                dp[j] = min(dp[j], dp[j-w] + 1);
            }
        }
        if (dp[amount] == amount+1){
            return -1;
        }
        return dp[amount];
    }
};