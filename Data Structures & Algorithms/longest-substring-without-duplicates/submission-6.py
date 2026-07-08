class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        ans = 0
        i, j = 0, 0
        seen = {}
        while j < len(s):
            seen[s[j]] = 1 + seen.get(s[j], 0)
            while i <= j and seen[s[j]] > 1:
                seen[s[i]] -= 1
                i += 1
            j += 1
            ans = max(ans, j-i)
        return ans
