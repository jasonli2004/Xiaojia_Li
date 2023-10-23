class Solution {
public:
    int findNonMinOrMax(vector<int>& nums) {
        if (nums.size() <= 2){
            return -1;
        }
    //     if (nums[0] < nums[1]){
    //         if (nums[1] < nums[2]){
    //             return nums[1];
    //         }
    //         if (nums[2] < nums[0]){
    //             return nums[0];
    //         }
    //         return nums[2];
    //     }
    //     if (nums[2] > nums[0]){
    //         return nums[0];
    //     }
    //     if (nums[1] < nums[2]){
    //         return nums[2];
    //     }
    //     return nums[1];
    // 
    sort(nums.begin(), nums.begin()+3);
    return nums[1];
    }
};