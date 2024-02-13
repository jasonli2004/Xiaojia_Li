class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int> count;
        for (int num : nums){
            count[num]++;
        }
        int cur_max = 0;
        int cur_cnt = -1;
        for (auto it : count){
            if (it.second > cur_cnt){
                cur_max = it.first;
                cur_cnt = it.second;
            }
        }
        return cur_max;
    }
};