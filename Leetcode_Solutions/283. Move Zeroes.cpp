class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int cur = 0;    
        for (int i = 0; i < nums.size(); i++){
            int num = nums[i];
            if (num != 0){
                nums[cur++] = nums[i]; 
            }
        }
        for (int i = cur; i < nums.size(); i++){
            nums[i] = 0;
        }
        return;
    }
};