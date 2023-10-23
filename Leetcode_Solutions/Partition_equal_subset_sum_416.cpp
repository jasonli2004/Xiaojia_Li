class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int W = accumulate(nums.begin(), nums.end(), 0);
        int N = nums.size();
        if (W%2){
            return false;
        }
        W = W/2;
        vector<int> dp(W+1, 0);
        for (int i = 1; i <= N; i++){
            int v = nums[i-1];
            for (int j = W; j >= v; j--){
                dp[j] = max(dp[j], dp[j-v] + v);
            }
        }
        return dp[W] == W;
    }
};