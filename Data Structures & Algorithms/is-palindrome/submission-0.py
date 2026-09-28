class Solution:
    def isAlphanumeric(self, c):
        return 'A' <= c <= 'Z' or 'a' <= c <= 'z' or '0' <= c <= '9'
    def isPalindrome(self, s: str) -> bool:
        n = len(s)
        i, j = 0, n-1
        while i <= j:
            if not self.isAlphanumeric(s[i]):
                i += 1
                continue
            if not self.isAlphanumeric(s[j]):
                j -= 1
                continue
            if s[i].lower() != s[j].lower():
                return False
            else:
                i += 1
                j -= 1
        return True
            