class Solution:
    def rob(self, nums: List[int]) -> int:
        prev = 0
        curr = nums[0]
        for i in range(1, len(nums)):
            take = nums[i] + prev
            notake = curr
            prev = curr
            curr = max(take, notake)
        return curr
