class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int lo = 0;
        int hi = nums.size() - 1;
        while(lo <= hi){
            int mid = lo + (hi - lo) / 2;
            if (nums[mid] == target){
                return true;
            }
            if (nums[mid] == nums[lo]){
                lo++;
            }
            else if(nums[mid] == nums[hi]){
                hi--;
            }
            else if (nums[mid] < nums[hi]){
                if (nums[hi] >= target && nums[mid] < target){
                    lo = mid + 1;
                }
                else{
                    hi = mid - 1;
                }
            }
            else{
                if (nums[lo] <= target && nums[mid] > target){
                    hi = mid - 1;
                }
                else{
                    lo = mid + 1;
                }
            }
        }
        return false;
    }
};