class Solution {
public:
    void dfs(int pos, vector<int>& cur, vector<int>& nums, vector<vector<int>>& ans){
        ans.push_back(cur);
        if (pos >= nums.size()){
            return;
        }
        for (int i = pos; i < nums.size(); i++){
            if (i != pos && nums[i] == nums[i-1]){
                continue;
            }
            cur.push_back(nums[i]);
            dfs(i+1, cur, nums, ans);
            cur.pop_back();
        }
        return;
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<int> v = {};
        dfs(0, v, nums, ans);
        return ans;
    }
};