# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def maxDepth(self, root: Optional[TreeNode]) -> int:
        self.ans = 0

        def solve(node, level):
            if not node:
                return
            self.ans = max(self.ans, level)
            solve(node.left, level+1)
            solve(node.right, level+1)
        solve(root, 1)
        return self.ans