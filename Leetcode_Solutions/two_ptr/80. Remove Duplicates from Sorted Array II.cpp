class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int slow = 0;
        int cur = -9999;
        int appear = 1;
        for (int i = 0; i < nums.size(); i++){
            int num = nums[i];
            if (num != cur){
                cur = num;
                appear = 1;
                nums[slow] = num;
                slow++;
            }
            else{
                if (appear == 1){
                    appear++;
                    nums[slow] = num;
                    slow++;
                }
            }
        }
        return slow;
    }
};