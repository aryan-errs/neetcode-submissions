class Solution:
    def generate(self, n: int) -> List[List[int]]:
        ans = []
        for i in range(n):
            arr = []
            for j in range(i+1):
                if j == 0 or j == i:
                    arr.append(1)
                elif i > 0:
                    arr.append(ans[i-1][j] + ans[i-1][j-1])
            ans.append(arr)
        return ans
