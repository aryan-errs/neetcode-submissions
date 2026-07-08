# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def goodNodes(self, root: TreeNode) -> int:
        self.cnt = 0
        def solve(node, maxVal):
            if not node:
                return
            if node.val >= maxVal:
                self.cnt += 1
                maxVal = node.val
            solve(node.left, maxVal)
            solve(node.right, maxVal)
        solve(root, float("-inf"))
        return self.cnt