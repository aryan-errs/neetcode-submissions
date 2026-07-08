class Solution:
    def combinationSum(self, nums: List[int], target: int) -> List[List[int]]:
        res = []
        nums.sort()
        def solve(i,t,temp):
            if t == 0:
                res.append(temp.copy())
                return
            if i == len(nums) or nums[i] > t:
                return 
            temp.append(nums[i])
            solve(i, t-nums[i], temp)
            temp.pop()
            solve(i+1, t, temp)
        solve(0, target, [])
        return res