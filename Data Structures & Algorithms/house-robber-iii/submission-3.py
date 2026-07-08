# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def rob(self, root: Optional[TreeNode]) -> int:
        dp = {}
        def solve(root):
            if not root:
                return 0
            if root in dp:
                return dp[root]
            take = root.val
            if root.left:
                take += solve(root.left.left)
                take += solve(root.left.right)
            if root.right:
                take += solve(root.right.left)
                take += solve(root.right.right)
            notake = 0
            if root.left:
                notake += solve(root.left)
            if root.right:
                notake += solve(root.right)
            dp[root] = max(take, notake)
            return dp[root]
        return solve(root)

            