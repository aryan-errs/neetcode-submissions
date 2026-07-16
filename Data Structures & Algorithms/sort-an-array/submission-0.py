class Solution:
    def sortArray(self, nums: List[int]) -> List[int]:
        pq = []
        for num in nums:
            heapq.heappush(pq, num)

        ans = []
        while pq:
            num = heapq.heappop(pq)
            ans.append(num)
        return ans