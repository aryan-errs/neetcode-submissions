# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def rob(self, root: Optional[TreeNode]) -> int:
        cache = {}

        def solve(node):
            if not node:
                return 0
            if node in cache:
                return cache[node]
            take = node.val
            if node.left:
                take += solve(node.left.left) + solve(node.left.right)
            if node.right:
                take += solve(node.right.left) + solve(node.right.right)
            notake = solve(node.left) + solve(node.right)
            cache[node] = max(take, notake)
            return max(take, notake)
        solve(root)
        return cache[root]
    
            

