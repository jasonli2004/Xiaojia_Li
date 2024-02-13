class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        if (n==1){
            return 0;
        }
        if (n == 2){
            if (nums[0] > nums[1]){
                return 0;
            }
            return 1;
        }
        int lo = 0;
        int hi = n;
        while (lo < hi){
            int mid = (lo+hi)/2;
            cout << lo << " , " << hi <<endl;
            if (mid == 0){
                if (nums[0] > nums[1]){
                    return 0;
                }
                return 1;
            }
            if (mid == n-1){
                if (nums[n-1] > nums[n-2]){
                    return n-1;
                }
                return n-2;
            }
            if (nums[mid] > nums[mid+1] && nums[mid] > nums[mid-1]){
                return mid;
            }
            if (nums[mid] <= nums[mid+1]){
                lo = mid+1;
            }
            else{
                hi = mid;
            }
        }
        return lo;
    }
};