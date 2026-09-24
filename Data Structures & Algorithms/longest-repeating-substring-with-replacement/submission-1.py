class Solution:
    def characterReplacement(self, s: str, k: int) -> int:
        ans = 0
        i, j = 0, 0
        mp = {}
        currMax = 0
        while j < len(s):
            mp[s[j]] = 1 + mp.get(s[j], 0)
            currMax = max(currMax, mp[s[j]])
            if j-i+1 - currMax <= k:
                ans = max(ans, j-i+1)
            if j-i+1 - currMax > k:
                mp[s[i]] -= 1
                i += 1
            j += 1
        return ans

