class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int fill_pos = 0;
        for (int num : nums){
            if (num != val){
                nums[fill_pos++] = num;
            }
        }
        return fill_pos;
    }
};