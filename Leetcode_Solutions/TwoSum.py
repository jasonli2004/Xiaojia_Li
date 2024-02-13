class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        numlen = len(nums)
        for i in range(0,numlen):
            for j in range(i+1, numlen):
                if (nums[i] + nums[j] == target):
                    return [i,j]
        return [0,1]