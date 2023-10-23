import java.util.Arrays;
class Solution {
    public void nextPermutation(int[] nums) {
        int minloc;
        for (int j = nums.length - 1; j >= 0 ;j--){
            if (j!=0 && nums[j-1] < nums[j]){
                minloc = j;
                for (int k = j + 1; k < nums.length; k++){
                    if (nums[k] >nums[j-1] && nums[k] < nums[minloc]){
                        minloc = k;
                    }
                }
                int temp = nums[j-1];
                nums[j-1] = nums[minloc];
                nums[minloc] = temp;
                Arrays.sort(nums, j, nums.length);
                return;
            }
        }
        Arrays.sort(nums);
        return;
    }
}

