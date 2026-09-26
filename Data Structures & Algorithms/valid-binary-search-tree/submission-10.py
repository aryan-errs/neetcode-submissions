# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def isValidBST(self, root: Optional[TreeNode]) -> bool:
        
        def solve(leftVal, rightVal, root):
            if not root:
                return True
            return leftVal < root.val < rightVal and solve(leftVal, root.val, root.left) and solve(root.val, rightVal, root.right)
        return solve(float("-inf"), float("inf"), root)
        