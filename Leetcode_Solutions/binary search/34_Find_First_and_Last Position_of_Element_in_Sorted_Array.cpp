class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int l = 0;
        int len = nums.size();
        int r = len;
        if (r == 0){
            return {-1,-1};
        }
        int mid;
        while (l < r){
            mid = l + (r - l) / 2;
            if (nums[mid] >= target){
                r = mid;
            }
            else{
                l = mid + 1;
            }
        }
        if (l >= len || nums[l] != target){
            return {-1,-1};
        }
        int lower = l;
        l = 0;
        r = len;
        while (l < r){
            mid = l + (r - l) / 2;
            if (nums[mid] > target){
                r = mid;
            }
            else{
                l = mid + 1;
            }
        }
        return {lower,r-1};
    }
};