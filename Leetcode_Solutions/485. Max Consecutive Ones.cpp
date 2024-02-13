class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        bool consecutive = true;
        int cur_max = 0;
        int cur_len = 0;
        for (int i : nums){
            if (i){
                consecutive = true;
                cur_len++;
            }
            else{
                consecutive = false;
                cur_max = max(cur_max, cur_len);
                cur_len = 0;
            }
        }
        cur_max = max(cur_max, cur_len);
        return cur_max;
    }
};