class Solution {
    List<List<Integer>> result =  new ArrayList<>();
    List<List<Integer>> copy =  new ArrayList<>();
    public List<List<Integer>> threeSum(int[] nums) {
        Arrays.sort(nums);
        List<Integer> a =  new ArrayList<Integer>();
        for (int k = 0; k < nums.length-1; k++){
            twoSum(Arrays.copyOfRange(nums, k+1, nums.length), 0 - nums[k], nums[k]);
        }
        return result;
    }
    private void twoSum(int[] nums, int target, int k) {
        HashMap<Integer, Integer> data = new HashMap<>();
        boolean put = false;
        for (int i = 0; i < nums.length; i++){
            data.put(nums[i],i);
        }
        for (int i = 0; i < nums.length; i++){
            if (data.containsKey(target-nums[i])){
                int temp = data.get(target - nums[i]);
                List<Integer> a = new ArrayList<Integer>();
                if (temp != i){
                    a.add(nums[i]);
                    a.add(nums[temp]);
                    a.add(k);
                    if (!copy.contains(a)){
                        result.add(a);
                        a = new ArrayList<Integer>();
                        a.add(nums[i]);
                        a.add(k);
                        a.add(nums[temp]);
                        copy.add(a);
                        a = new ArrayList<Integer>();
                        a.add(nums[i]);
                        a.add(nums[temp]);
                        a.add(k);
                        copy.add(a);
                        a = new ArrayList<Integer>();
                        a.add(nums[temp]);
                        a.add(nums[i]);
                        a.add(k);
                        copy.add(a);
                        a = new ArrayList<Integer>();
                        a.add(nums[temp]);
                        a.add(k);
                        a.add(nums[i]);
                        copy.add(a);
                        a = new ArrayList<Integer>();
                        a.add(k);
                        a.add(nums[temp]); 
                        a.add(nums[i]);
                        copy.add(a);
                        a = new ArrayList<Integer>();
                        a.add(k);
                        a.add(nums[i]);
                        a.add(nums[temp]);
                        copy.add(a);

                    }
                    put = true;
                }
            }
        }
        return;
    }
}