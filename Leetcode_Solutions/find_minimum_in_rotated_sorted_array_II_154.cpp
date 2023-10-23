class Solution {
public:
    int findMin(vector<int>& nums) {
        int lo = 0;
        int hi = nums.size() - 1;
        int mid;
        if (nums[lo] < nums[hi]){
            return nums[0];
        }
        while (lo < hi - 1){
            mid = lo + (hi - lo)/2;
            if (nums[mid] == nums[hi]){
                hi--;
            }
            else if (nums[mid] == nums[lo]){
                lo++;
            }
            else if (nums[hi] > nums[mid]){
                hi = mid;
            }
            else{
                lo = mid;
            }
        }
        if (lo >= nums.size()){
            return nums[hi];
        }
        if (hi >= nums.size()){
            return nums[lo];
        }
        return min(nums[lo], nums[hi]);
    }
};

