class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size();
        int mid;
        int cur;
        while (l < r){
            mid = l + (r - l)/2;
            cur = nums[mid];
            if (cur == target){
                return mid;
            }
            else if (cur < target){
                l = mid + 1;
            }
            else{
                r = mid;
            }
        }
        return -1;
    }
};