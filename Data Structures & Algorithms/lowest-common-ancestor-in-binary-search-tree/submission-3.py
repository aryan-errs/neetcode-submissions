# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def lowestCommonAncestor(self, root: TreeNode, p: TreeNode, q: TreeNode) -> TreeNode:
        
        def solve(root, minVal, maxVal):
            if not root:
                return root
            if root.val == minVal or root.val == maxVal or minVal < root.val < maxVal:
                return root
            if root.val < minVal:
                return solve(root.right, minVal, maxVal)
            return solve(root.left, minVal, maxVal)
        return solve(root, min(p.val, q.val), max(p.val, q.val))
            