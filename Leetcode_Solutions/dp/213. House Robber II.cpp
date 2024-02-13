class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 1){
            return nums[0];
        }
        if (nums.size() == 2){
            return max(nums[0],nums[1]);
        }
        if (nums[0] + nums[2] < nums[1]){
            int first = nums[0];
            int second = max(nums[0], nums[1]);
            for (int i = 2; i < nums.size(); i++){
                int temp = max(first + nums[i], second);
                first = second;
                second = temp;
            }
            return max(first, second);
        }
        else{
            int first = nums[0];
            int second = max(nums[0], nums[1]);
            for (int i = 2; i < nums.size() - 1; i++){
                int temp = max(first + nums[i], second);
                first = second;
                second = temp;
            }
            int n1 = max(first, second);
            first = nums[1];
            second = max(nums[1], nums[2]);
            for (int i = 3; i < nums.size(); i++){
                int temp = max(first + nums[i], second);
                first = second;
                second = temp;
            }
            int n2 = max(first, second);
            return max(n1,n2);
        }
        return 0;
    }
};