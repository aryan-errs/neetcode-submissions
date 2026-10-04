class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        currMin = prices[0]
        ans = 0
        for price in prices:
            ans = max(ans, price - currMin)
            currMin = min(price, currMin)
        return ans