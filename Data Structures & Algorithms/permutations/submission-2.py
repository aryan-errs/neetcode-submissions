class Solution:
    def permute(self, nums: List[int]) -> List[List[int]]:
        res = []
        def solve(index, temp):
            if index == len(nums):
                res.append(temp.copy())
                return
            for i in range(index, len(nums)):
                temp[index], temp[i] = temp[i], temp[index]
                solve(index+1, temp)
                temp[index], temp[i] = temp[i], temp[index]
        solve(0, nums)
        return res