class TrieNode:
    def __init__(self):
        self.child = [None] * 26
        self.isEnd = False


class PrefixTree:

    def __init__(self):
        self.root = TrieNode()

    def insert(self, word: str) -> None:
        if not self.root:
            self.root = TrieNode()
        curr = self.root
        for c in word:
            if not curr.child[ord(c)-ord('a')]:
                curr.child[ord(c)-ord('a')] = TrieNode()
            curr = curr.child[ord(c)-ord('a')]
        curr.isEnd = True

    def search(self, word: str) -> bool:
        curr = self.root
        for c in word:
            if curr.child[ord(c)-ord('a')] == None:
                return False
            curr = curr.child[ord(c)-ord('a')]
        return curr.isEnd

    def startsWith(self, prefix: str) -> bool:
        curr = self.root
        for c in prefix:
            if curr.child[ord(c)-ord('a')] == None:
                return False
            curr = curr.child[ord(c)-ord('a')]
        return True
        