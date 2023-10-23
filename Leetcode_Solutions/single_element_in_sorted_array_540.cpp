class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int lo = 0;
        int hi = nums.size() - 1;
        while (lo <= hi){
            int mid = lo + (hi - lo) / 2;
            if (mid%2 == 0){
                if ( mid + 1 < nums.size() && nums[mid] == nums[mid + 1]){
                    lo = mid + 1;
                }
                else if (mid - 1 >= 0 && nums[mid] == nums[mid - 1]){
                    hi = mid - 1;
                }
                else{
                    return nums[mid];
                }
            }
            else{
                if ( mid + 1 < nums.size() && nums[mid] == nums[mid + 1]){
                    hi = mid - 1;
                }
                else if (mid - 1 >= 0 && nums[mid] == nums[mid - 1]){
                    lo = mid + 1;
                }
                else{
                    return nums[mid];
                }
            }
        }
        return 0;
    }
};