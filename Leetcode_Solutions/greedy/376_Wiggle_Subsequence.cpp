class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int len = nums.size();
        if (len == 1){
            return len;
        }
        int cnt = 1;
        int state = cal_state(1,nums);
        int temp_state;
        if (state != 1){
            cnt++;
        }
        for (int i = 2; i < nums.size(); i++){
            temp_state = cal_state(i, nums);
            if (state == 1 &&  temp_state != 1){
                cnt++;
                state = temp_state;
            }
            else if (state == 2 && temp_state == 0){
                cnt++;
                state = 0;
            }
            else if (state == 0 && temp_state == 2){
                cnt++;
                state = 2;
            }
        }
        return cnt;
    }
    int cal_state(int i, vector<int>& nums){
        int state = 0;
        int diff= nums[i] - nums[i-1];
        if (diff > 0){
            state = 2;
        }
        else if (diff == 0){
            state = 1;
        }
        else{
            state = 0;
        }
        return state;
    }
};