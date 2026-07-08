# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def helper(self, root: TreeNode, minVal: int, maxVal: int):
        if not root:
            return None
        if minVal <= root.val <= maxVal:
            return root
        if root.val > maxVal:
            return self.helper(root.left, minVal, maxVal)
        return self.helper(root.right, minVal, maxVal)
    def lowestCommonAncestor(self, root: TreeNode, p: TreeNode, q: TreeNode) -> TreeNode:
        minVal, maxVal = min(p.val, q.val), max(p.val, q.val)
        return self.helper(root, minVal, maxVal)