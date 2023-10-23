class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        backtrack(nums, 0, ans);
        return ans;
    }

    void backtrack(vector<int>&nums, int level, vector<vector<int>>& ans){
        if (level == nums.size() - 1){
            ans.push_back(nums);
        }
        for (int i = level; i < nums.size(); i++){
            swap(nums[i], nums[level]);
            backtrack(nums, level+1, ans);
            swap(nums[i], nums[level]);
        }
    }
};