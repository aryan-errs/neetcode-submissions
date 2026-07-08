class Solution:
    def rob(self, nums: List[int]) -> int:
        prev = 0
        curr = nums[0]
        for i in range(1, len(nums)):
            temp = nums[i]
            if i > 1:
                temp += prev
            prev = curr
            curr = max(temp, curr)
        return curr