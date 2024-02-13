class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        ptr = 0
        for i in range(1, len(nums)):
            if (nums[ptr] != nums[i]):
                nums[ptr+1] = nums[i]
                ptr = ptr + 1
        return ptr+1