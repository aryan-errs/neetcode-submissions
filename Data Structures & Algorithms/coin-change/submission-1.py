class Solution:
    def coinChange(self, coins: List[int], amount: int) -> int:
        dp = [10**9] * (amount + 1)
        dp[0] = 0
        for a in range(1,amount+1):
            for i in range(len(coins)):
                if coins[i] <= a:
                    dp[a] = min(dp[a], 1 + dp[a-coins[i]])
        return dp[-1] if dp[-1] != 10**9 else -1