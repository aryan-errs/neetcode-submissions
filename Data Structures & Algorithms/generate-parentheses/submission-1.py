class Solution:
    def generateParenthesis(self, n: int) -> List[str]:
        res = []
        def solve(left, right, s):
            if left == 0 and right == 0:
                res.append(s)
                return
            if left > 0:
                solve(left-1, right, s + "(")
            if left < right:
                solve(left, right-1, s + ")")
        solve(n, n, "")
        return res