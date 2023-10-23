class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> start;
        backtrack(ans, nums, start, 0);
        return ans;
    }

    void backtrack(vector<vector<int>>& ans, vector<int>& nums, vector<int>& v, int curpos){
        ans.push_back(v);
        for (int i = curpos; i < nums.size(); i++){
            if (nums[i] != 11){
                v.push_back(nums[i]);
                int temp = nums[i];
                nums[i] = 11;
                backtrack(ans, nums, v, i+1);
                v.pop_back();
                nums[i] = temp;
            }
        }
    }
};