class Solution:
    def lengthOfLastWord(self, s: str) -> int:
        words = s.split()
        lIndex = len(words) - 1
        return  len(words[lIndex])