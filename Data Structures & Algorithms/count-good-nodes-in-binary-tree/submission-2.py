# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def goodNodes(self, root: TreeNode) -> int:
        def solve(root, maxVal):
            if not root:
                return 0
            isGood = 0
            if root.val >= maxVal:
                maxVal = root.val
                isGood = 1
            return isGood + solve(root.left, maxVal) + solve(root.right, maxVal)
        return solve(root, -101)