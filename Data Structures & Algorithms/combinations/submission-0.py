class Solution:
    def combine(self, n: int, k: int) -> List[List[int]]:
        res = []
        def solve(i, temp):
            if len(temp) == k:
                res.append(temp.copy())
                return
            if i > n:
                return
            temp.append(i)
            solve(i+1, temp)
            temp.pop()
            solve(i+1, temp)
        solve(1, [])
        return res
