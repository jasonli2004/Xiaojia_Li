class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int first = nums[0];
        int cur_max = first;
        for (int i = 1; i < nums.size(); i++){
            first = max(nums[i], nums[i]+first);
            cur_max = max(cur_max, first);
        }
        return cur_max;
    }
};


