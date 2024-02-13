class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size();
        int mid;
        while (l < r){
            mid = l + (r - l) / 2;
            int mid_num = nums[mid];
            if (mid_num == target){
                return mid;
            }
            if (nums[l] <= mid_num){
                if (target >= nums[l] && target <= mid_num){
                    r = mid;
                }
                else{
                    l = mid + 1;
                }
            }
            else{
                if (mid_num <= target && target <= nums[r-1]){
                    l = mid + 1;
                }
                else{
                    r = mid;
                }
            }
        }
        return -1;
    }
};