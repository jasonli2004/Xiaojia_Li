class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int len = nums.size();
        int global_max = 1;
        vector<int> dp(len, 1);
        for (int i = 1; i < len; i++){
            int cur_max = 1;
            for (int j = 0; j < i; j++){
                if (nums[j] < nums[i]){
                    cur_max = max(cur_max, dp[j]+1);
                }

            }
            dp[i] = cur_max;
            global_max = max(global_max, cur_max);
        }
        return global_max;
    }
};