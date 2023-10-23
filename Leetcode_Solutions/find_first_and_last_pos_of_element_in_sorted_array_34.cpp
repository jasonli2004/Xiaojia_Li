class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int lo = 0;
        int hi = nums.size();
        int mid;
        while (lo < hi){
            mid = (lo+hi-1)/2;
            if (nums[mid] >= target){
                hi = mid;
            }
            else{
                lo = mid + 1;
            }
        }
        int lowerb = lo;
        lo = 0;
        hi = nums.size();
        while (lo < hi){
            mid = (lo+hi-1)/2;
            if (nums[mid] > target){
                hi = mid;
            }
            else{
                lo = mid + 1;
            }
        }
        int higherb = lo;
        if (lowerb >= nums.size() || nums[lowerb] != target){
            return vector<int>{-1, -1};
        }
        return vector<int>{lowerb, higherb-1};
    }
};