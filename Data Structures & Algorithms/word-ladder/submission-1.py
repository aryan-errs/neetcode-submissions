class Solution:
    def ladderLength(self, beginWord: str, endWord: str, wordList: List[str]) -> int:
        q = []
        heapq.heappush(q,[1,beginWord])
        wordList.append(beginWord)
        while q:
            num, word = heapq.heappop(q)
            if word == endWord:
                return num
            for i in range(len(word)):
                for j in range(26):
                    c = chr(ord('a') + j)
                    newWord = word[:i] + c + word[i+1:]
                    if newWord in wordList:
                        heapq.heappush(q, [num+1, newWord])
                        wordList.remove(newWord)
        return 0
