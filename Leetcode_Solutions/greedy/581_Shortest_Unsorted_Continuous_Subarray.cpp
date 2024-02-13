class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int len = nums.size();
        int down_max = len - 1;
        for (int i = 1; i < len; i++){
            if (nums[i] < nums[i-1]){
                down_max = i - 2;
                break;
            }
        }
        if (down_max == len-1){
            return 0;
        }
        int abs_down;
        if (down_max >= 0){
            abs_down = nums[down_max + 1];
            for (int i = down_max + 1; i < len;i++){
                if (abs_down > nums[i]){
                    abs_down = nums[i];
                }
            }
            for (int i = 0; i <= down_max; i++){
                if (abs_down < nums[i]){
                    down_max = i - 1;
                    break;
                }
            }
        }
        int up_min = 0;
        for (int i = len - 2; i >= 0; i--){
            if (nums[i] > nums[i+1]){
                up_min = i + 2;
                break;
            }
        }
        int abs_up;
        if (up_min <= len){
            abs_up = nums[up_min - 1];
            for (int i = up_min - 1; i >= 0;i--){
                if (abs_up < nums[i]){
                    abs_up = nums[i];
                }
            }
            for (int i = len - 1; i >= up_min; i--){
                if (abs_up > nums[i]){
                    up_min = i + 1;
                    break;
                }
            }
        }
        return up_min - down_max - 1;
    }
};