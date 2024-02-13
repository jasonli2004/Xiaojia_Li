class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        unordered_map<int,int> count;
        int cur_max = -1;
        for (int num : nums){
            count[num]++;
            cur_max = max(count[num], cur_max);
        }
        vector<vector<int>> ans(cur_max);
        for (auto it : count){
            int cur_count = it.second;
            int cur_num = it.first;
            for (int i = 0; i < cur_count; i++){
                ans[i].push_back(cur_num);
            }
        }
        return ans;
    }
};