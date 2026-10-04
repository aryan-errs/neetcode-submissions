class Solution:
    def maxSlidingWindow(self, nums: List[int], k: int) -> List[int]:
        i = j = 0
        heap = []
        while len(heap) < k:
            heapq.heappush_max(heap, (nums[j], j))
            j += 1
        ans = []
        ans.append(heap[0][0])
        while j < len(nums):
            while len(heap) >= k and heap[0][1] <= i:
                heapq.heappop_max(heap)
            heapq.heappush_max(heap, (nums[j], j))
            ans.append(heap[0][0])
            i += 1
            j += 1
        return ans
