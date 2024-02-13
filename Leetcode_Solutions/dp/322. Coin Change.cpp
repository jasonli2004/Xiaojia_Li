class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1, 10086);
        if (amount == 0){
            return 0;
        }
        for (int num : coins){
            if (num <= amount){
                dp[num] = 1;
            }
        }
        for (int i = 1; i <= amount; i++){
            for (int num : coins){
                if (i - num > 0 && dp[i - num] != 10086){
                    dp[i] = min(dp[i], dp[i-num] + 1);
                }
            }
        }
        if (dp[amount] == 10086){
            return -1;
        }
        return dp[amount];
    }
};