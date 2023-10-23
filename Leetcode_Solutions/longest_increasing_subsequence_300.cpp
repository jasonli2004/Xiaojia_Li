class Solution {
public:
    // int lengthOfLIS(vector<int>& nums) {
    //     int maxlen = 1; 
    //     int len = nums.size();
    //     vector<int> dp(len+1, 1);
    //     for (int i = 1; i < len; i++){
    //         int cur = nums[i];
    //         int innermax = 0;
    //         for (int j = i - 1; j >= 0; j--){
    //             if (nums[j] < cur && innermax < dp[j]){
    //                 innermax = dp[j];
    //             }
    //         }
    //         dp[i] = innermax + 1;
    //         maxlen = max(maxlen, dp[i]);
    //     }
    //     return maxlen;
    // }

    int lengthOfLIS(vector<int>& nums) {
        int len = nums.size();
        vector<int> dp;
        dp.push_back(nums[0]);
        for (int i = 1; i < len; i++){
            int cur = nums[i];
            if (cur > dp.back()){
                dp.push_back(cur);
            }
            else{
                auto itr = lower_bound(dp.begin(),dp.end(), cur);
                *itr = cur;
            }
        }
        return dp.size();
    }
};