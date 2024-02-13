import java.util.Arrays;
class Solution {
    public void nextPermutation(int[] nums) {
        int len = nums.length;
        int last;
        boolean original = true;
        for (int j = len - 1; j >= 0 ;j--){
            if (original == false){
                break;
            }
            last = nums[j];
            if (j!=0 && nums[j-1] < last){
                original = false;
                int min = nums[j];
                int minloc = j;
                for (int k = j + 1; k < len; k++){
                    if (nums[k]>nums[j-1] && nums[k]<min){
                        min = nums[k];
                        minloc = k;
                    }
                }
                swap(j-1,minloc,nums);
                Arrays.sort(nums, j, len);
                break;
            }
            for (int i = nums.length - 1; i > j; i--){
                if (nums[i] > last){
                    original = false;
                    swap(j, i, nums);
                    Arrays.sort(nums, j+1, len);
                    break;
                }
            }
        }
        if (original){
            Arrays.sort(nums);
            System.out.println("yes");
            return;
        }
        else{
            return;
        }
        
    }
    /*private void reverse(int i, int[] num){
        int p = i + 1;
        int q = num.length - 1;
        while (p < q){
            swap(p,q,num);
            p++;
            q--;
        }
    }*/

    private void swap(int i, int j, int[] num){
        int temp = num[i];
        num[i] = num[j];
        num[j] = temp;
        return;
    }
}

