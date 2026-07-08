class Solution:
    def maxSlidingWindow(self, nums: List[int], k: int) -> List[int]:
        def maxEl(start:int, end:int, nums:List[int]) -> int:
            maxEl = nums[start]
            while start < end:
                maxEl = max(maxEl, nums[start])
                start += 1
            return maxEl
        
        i,j = 0, k
        ans = []
        while j <= len(nums):
            maxi = maxEl(i,j,nums)
            ans.append(maxi)
            i += 1
            j += 1
        return ans