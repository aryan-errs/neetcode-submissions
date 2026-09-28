class Solution:
    def minWindow(self, s: str, t: str) -> str:
        ms = {}
        mt = {}
        for c in t:
            mt[c] = 1 + mt.get(c, 0)
        need = len(t)
        i = j = 0
        minlen = float("inf")
        curr = 0
        ans = ""
        while j < len(s):
            ms[s[j]] = 1 + ms.get(s[j], 0)
            if s[j] in mt and ms[s[j]] <= mt[s[j]]:
                curr += 1
            while i <= j and curr == need:
                if minlen > j-i+1:
                    minlen = j - i + 1
                    ans = s[i:i+minlen]
                ms[s[i]] -= 1
                if s[i] in mt and ms[s[i]] < mt[s[i]]:
                    curr -= 1
                i += 1
            j += 1
        return ans