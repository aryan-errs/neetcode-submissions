class KthLargest:

    def __init__(self, k: int, nums: List[int]):
        self.q = []
        for num in nums:
            heapq.heappush(self.q, num)
            if len(self.q) > k:
                heapq.heappop(self.q)
        self.k = k

    def add(self, val: int) -> int:
        heapq.heappush(self.q, val)
        if len(self.q) > self.k:
                heapq.heappop(self.q)
        return self.q[0]
