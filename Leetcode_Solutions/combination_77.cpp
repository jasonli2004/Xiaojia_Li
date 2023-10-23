class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<int> nums(k, 0);
        vector<vector<int>> ans;
        backtrack(n, k, 0, 1, nums, ans);
        return ans;
    }

    void backtrack(int n, int k, int level, int pos, vector<int>& nums, vector<vector<int>>& ans) {
        if (level == k) {
            ans.push_back(nums);
            return;
        }
        for (int i = pos; i <= n; i++) {
                nums[level] = i;
                backtrack(n, k, level + 1, i + 1, nums, ans);
        }
    }
};