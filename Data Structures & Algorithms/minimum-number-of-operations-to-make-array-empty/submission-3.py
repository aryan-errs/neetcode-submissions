class Solution:
    def minOperations(self, nums: List[int]) -> int:
        cnt = {}
        for num in nums:
            cnt[num] = 1 + cnt.get(num, 0)
        ops = 0

        for k, v in cnt.items():
            if v < 2:
                return -1
            if v % 3 == 1:
                ops += (v - 4) // 3 + 2
            elif v % 3 == 2:
                ops += (v-2) // 3 + 1
            else:
                ops += v // 3
        return ops