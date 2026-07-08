class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        res = []

        def solve(i, temp):
            if i == len(nums):
                res.append(temp.copy())
                return
            temp.append(nums[i])
            solve(i+1, temp)
            temp.pop()
            solve(i+1, temp)
        solve(0, [])
        return res