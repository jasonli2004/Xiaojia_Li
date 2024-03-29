class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int lo = 0;
        int hi = nums.size();
        if (hi <= 1){
            return nums[0];
        }
        while (lo < hi){
            int mid = (lo+hi)/2;
            if (mid % 2 == 1){
                if (nums[mid] != nums[mid-1]){
                    hi = mid;
                }
                else{
                    lo = mid + 1;
                }
            }
            else{
                if (mid+1 == nums.size()){
                    return nums[mid];
                }
                if (nums[mid] != nums[mid+1]){
                    hi = mid;
                }
                else{
                    lo = mid + 1;
                }
            }
        }
        return nums[lo];
    }
};