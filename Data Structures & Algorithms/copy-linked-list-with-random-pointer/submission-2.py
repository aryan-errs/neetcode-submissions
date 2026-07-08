"""
# Definition for a Node.
class Node:
    def __init__(self, x: int, next: 'Node' = None, random: 'Node' = None):
        self.val = int(x)
        self.next = next
        self.random = random
"""

class Solution:
    def copyRandomList(self, head: 'Optional[Node]') -> 'Optional[Node]':
        mp = {}
        def solve(node):
            if not node:
                return node
            if node in mp:
                return mp[node]
            copy = Node(node.val)
            mp[node] = copy
            copy.next = solve(node.next)
            copy.random = solve(node.random)
            return copy
        return solve(head)