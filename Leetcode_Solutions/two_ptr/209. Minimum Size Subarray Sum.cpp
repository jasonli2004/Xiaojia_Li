class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
        int cur_min = 200000;
        int cur = 0;
        int ptr = 0;
        int len = nums.size();
        for (int i = 0; i < len; i++){
            int num = nums[i];
            cur = cur + num;
            while (cur >= target){
                cur_min = min(cur_min, i - ptr + 1);
                cur = cur - nums[ptr++];
            }
        }
        if (cur_min ==200000){
            return 0;
        }
        return cur_min;
    }
};
