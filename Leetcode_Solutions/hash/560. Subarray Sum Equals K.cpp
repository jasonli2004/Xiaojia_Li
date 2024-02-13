class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int ans = 0;
        unordered_map<int,int> cnt;
        cnt[0] = 1;
        int cur_sum = 0;
        for (int num : nums){
            cur_sum += num;
            if (cnt.find(cur_sum - k) != cnt.end()){
                ans += cnt[cur_sum - k];
            }
            cnt[cur_sum]++;
        }
        return ans;
    }   
};