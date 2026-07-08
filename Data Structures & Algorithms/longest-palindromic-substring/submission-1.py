class Solution:
    def longestPalindrome(self, s: str) -> str:
        res = ""
        for i in range(len(s)):
            l = i-1
            h = i+1
            temp = ""
            temp += s[i]
            while l >= 0 and h < len(s) and s[l] == s[h]:
                temp = s[l] + temp + s[h]
                l -= 1
                h += 1
            if len(temp) > len(res):
                res = temp
            l = i
            h = i + 1
            temp = ""
            while l >= 0 and h < len(s) and s[l] == s[h]:
                temp = s[l] + temp + s[h]
                l -= 1
                h += 1
            if len(temp) > len(res):
                res = temp
        return res