class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int len = nums.size();
        vector<int> v;
        for (int i = 0; i < len; i++){
            if (i == 0){
                v.push_back(nums[i]);
            }
            else if (nums[i] > v.back()){
                v.push_back(nums[i]);
            }
            else{
                auto it = lower_bound(v.begin(),v.end(), nums[i]);
                *it = nums[i];
            }
        }
        return v.size();
    }
};