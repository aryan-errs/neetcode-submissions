class Solution:
    def solve(self, nums: List[int]) -> int:
        prev = 0
        curr = nums[0]
        for i in range(1, len(nums)):
            take = nums[i] + prev
            notake = curr
            prev = curr
            curr = max(take, notake)
        return curr
    def rob(self, nums: List[int]) -> int:
        if len(nums) == 1:
            return nums[0]
        return max(self.solve(nums[0:len(nums)-1]), self.solve(nums[1:]))