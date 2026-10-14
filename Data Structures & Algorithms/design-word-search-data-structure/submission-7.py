class TrieNode:

    def __init__(self):
        self.child = [None] * 26
        self.isEnd = False
class WordDictionary:

    def __init__(self):
        self.root = TrieNode()

    def addWord(self, word: str) -> None:
        if not self.root:
            self.root = TrieNode()
        curr = self.root
        for c in word:
            if not curr.child[ord(c)-ord('a')]:
                curr.child[ord(c)-ord('a')] = TrieNode()
            curr = curr.child[ord(c)-ord('a')]
        curr.isEnd = True

    def helper(self, node, word) -> bool:
        if not node:
            return False
        if not word:
            return node.isEnd
        if word[0] == '.':
            for i in range(26):
                if node.child[i]:
                    if self.helper(node.child[i], word[1:]):
                        return True
            return False
        return self.helper(node.child[ord(word[0]) - ord('a')], word[1:])

    def search(self, word: str) -> bool:
        curr = self.root
        if not curr:
            return False
        return self.helper(curr, word)
