class Solution {
public:
    void sortColors(vector<int>& nums) {
        int zero = 0;
        int one = 0;
        int two = 0;
        for (int i = 0; i < nums.size(); i++){
            if (nums[i] == 0){
                zero++;
            }
            else if (nums[i] == 1){
                one++;
            }
            else{
                two++;
            }
        }
        int cnt = 0;
        while (zero > 0){
            nums[cnt] = 0;
            zero--;
            cnt++;
        }
        while (one > 0){
            nums[cnt] = 1;
            one--;
            cnt++;
        }
        while (two > 0){
            nums[cnt] = 2;
            two--;
            cnt++;
        }
    }
};

//approach #2 swapping 3-way quicksort

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int zero = 0, two = nums.size() - 1;
        int one = 0;
        while (one <= two){
            if (nums[one] == 0){
                swap(nums[zero], nums[one]);
                zero++;
                one++;
            }
            else if (nums[one] == 1){
                one++;
            }
            else{
                swap(nums[two], nums[one]);
                two--;
            }
        }
    }
};