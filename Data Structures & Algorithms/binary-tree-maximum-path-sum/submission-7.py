# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def maxPathSum(self, root: Optional[TreeNode]) -> int:
        self.ans = float("-inf")
        def solve(root):
            if not root:
                return 0
            lh = solve(root.left)
            rh = solve(root.right)
            self.ans = max(self.ans, lh + rh + root.val)
            return max(0, max(lh,rh)+root.val)
        solve(root)
        return self.ans
