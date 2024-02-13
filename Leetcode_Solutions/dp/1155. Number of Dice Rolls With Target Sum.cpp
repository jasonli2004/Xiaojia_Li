class Solution {
public:
    int numRollsToTarget(int n, int k, int target) {
        vector<long long> dp(target + 1, 0);
        int m=1000000007;
        for (int i = 1; i <= min(k, target); i++){
            dp[i] = 1;
        }
        for (int i = 2; i <= n; i++){
            for (int j = min(target, i * k); j >= i; j--){
                long long temp = 0;
                for (int h = 1; h <= min(k,j); h++){
                    temp = (temp + dp[j - h]) % m;
                }
                dp[j] = temp;
            }
            for (int s = 0; s < i; s++){
                dp[s] = 0;
            }
        }
        return dp[target];
    }
};

