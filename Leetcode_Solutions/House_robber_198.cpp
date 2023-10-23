class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size()==1){
            return nums[0];
        }
        int first = nums[0];
        int second = max(nums[0], nums[1]);
        int temp = 0;
        for (int i = 2; i < nums.size(); i++){
            temp = max(first+nums[i], second);
            first = second;
            second = temp;
        }
        return second;
    }
};