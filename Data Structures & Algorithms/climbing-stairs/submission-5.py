class Solution:
    def climbStairs(self, n: int) -> int:
        prev, curr = 1, 1
        for i in range(n):
            temp = prev + curr
            prev = curr
            curr = temp
        return prev