class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int len = nums.size();
        if (len < 3){
            return 0;
        }
        int prev = 0;
        int total = 0;
        for (int i = 2; i < len; i++){
            if (nums[i]-nums[i-1] == nums[i-1] - nums[i-2]){
                prev++;
                total += prev;
            }
            else{
                prev = 0;
            }
        }
        return total;
    }
};