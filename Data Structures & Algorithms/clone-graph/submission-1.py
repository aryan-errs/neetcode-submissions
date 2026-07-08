"""
# Definition for a Node.
class Node:
    def __init__(self, val = 0, neighbors = None):
        self.val = val
        self.neighbors = neighbors if neighbors is not None else []
"""

class Solution:
    def cloneGraph(self, node: Optional['Node']) -> Optional['Node']:
        mp = {}
        mp[None] = None
        def solve(node):
            if not node:
                return
            if node in mp:
                return mp[node]
            copy = Node(node.val)
            mp[node] = copy
            for i in node.neighbors:
                copy.neighbors.append(solve(i))
            return copy
        return solve(node)