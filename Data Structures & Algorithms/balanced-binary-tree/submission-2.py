# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def isBalanced(self, root: Optional[TreeNode]) -> bool:
        if not root:
            return True
        left = self.height(root.left)
        right = self.height(root.right)
        if abs(left-right) > 1:
            return False
        return self.isBalanced(root.left) and self.isBalanced(root.right)
        
    def height(self, node: TreeNode) -> int:
        if not node:
            return 0
        lh = self.height(node.left)
        rh = self.height(node.right)
        return 1 + max(lh, rh)