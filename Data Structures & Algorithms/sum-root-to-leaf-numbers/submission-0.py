# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def sumNumbers(self, root: Optional[TreeNode]) -> int:
        
        def solve(node, currVal):
            if not node:
                return 0
            currVal = currVal * 10 + node.val
            if not node.left and not node.right:
                return currVal
            return solve(node.left, currVal) + solve(node.right, currVal)
            
        return solve(root, 0)