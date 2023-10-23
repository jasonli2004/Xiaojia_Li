class Solution {
    public int threeSumClosest(int[] nums, int target) {

        int closest = Integer.MAX_VALUE;
        int len = nums.length;
        Arrays.sort(nums);
        for (int i = 0; i < len - 2; i++){
            int p = i + 1;
            int q = len  - 1;
            while (p < q){
                int sum = nums[i]+nums[p]+nums[q];
                if (Math.abs(target-sum) < Math.abs(target - closest)){
                            closest = sum;
                }
                if (target < sum){
                    q--;
                }
                else{
                    p++;
                }
            }
        }
        return closest;
    }
}