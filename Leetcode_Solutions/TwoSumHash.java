import java.utils.*;
class Solution {
    public int[] twoSum(int[] nums, int target) {
        HashMap<Integer, Integer> data = new HashMap<>();
        for (int i = 0; i < nums.length; i++){
            data.put(nums[i],i);
        }
        for (int i = 0; i < nums.length; i++){
            if (data.containsKey(target-nums[i])){
                int temp = data.get(target - nums[i]);
                if (temp != i){
                    return new int[]{i,temp};
                }
            }
        }
        return null;
    }
}