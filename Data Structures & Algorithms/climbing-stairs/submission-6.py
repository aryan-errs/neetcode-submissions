class Solution:
    def climbStairs(self, n: int) -> int:
        prev, curr = 1, 1
        for i in range(2, n+1):
            temp = curr + prev
            prev = curr
            curr = temp
        return curr