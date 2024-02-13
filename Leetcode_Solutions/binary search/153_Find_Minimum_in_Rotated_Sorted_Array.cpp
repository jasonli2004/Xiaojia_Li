class Solution {
public:
    bool check_mid(int index,vector<int>& nums){
        if (index == 0){
            return nums[nums.size()-1] > nums[index] && nums[1] > nums[index];
        }
        else if (index == nums.size() - 1){
            return nums[index - 1] > nums[index] && nums[0] > nums[index];
        }
        else{
            return nums[index - 1] > nums[index] && nums[index + 1] > nums[index];
        }
        return true;
    }
    int findMin(vector<int>& nums) {
        int l = 0;
        int r = nums.size();
        if (r == 1){
            return nums[0];
        }
        if (r == 2){
            if (nums[0] < nums[1]){
                return nums[0];
            }
            return nums[1];
        }
        int mid;
        while (l < r){
            mid = l + (r - l) / 2;
            if (check_mid(mid, nums)){
                return nums[mid];
            }
            else if (nums[mid] > nums[r - 1]){
                l = mid + 1;
            }
            else{
                r = mid;
            }
        }
        return nums[l];
    }
};