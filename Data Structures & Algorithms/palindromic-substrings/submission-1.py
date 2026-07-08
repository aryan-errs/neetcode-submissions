class Solution:
    def countSubstrings(self, s: str) -> int:
        res = len(s)
        for i in range(len(s)):
            l = i-1
            h = i+1
            while l >= 0 and h < len(s) and s[l] == s[h]:
                res += 1
                l -= 1
                h += 1
            l = i
            h = i + 1
            while l >= 0 and h < len(s) and s[l] == s[h]:
                res += 1
                l -= 1
                h += 1
        return res