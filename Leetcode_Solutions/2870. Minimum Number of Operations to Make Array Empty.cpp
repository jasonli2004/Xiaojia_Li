class Solution {
public:
    int minOperations(vector<int>& nums) {
        unordered_map<int,int> count;
        int ans = 0;
        for (int num : nums){
            count[num]++;
        }
        for (auto it : count){
            if (it.second == 1){
                return -1;
            }
            ans += it.second/3;
            if (it.second%3 != 0){
                ans++;
            }
        }
        return ans;
    }
};