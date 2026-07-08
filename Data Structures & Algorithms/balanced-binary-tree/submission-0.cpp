/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
private: 
    int solve(TreeNode* root, int &ans){
        if(!root) return 0;
        int lh = solve(root->left, ans);
        int rh = solve(root->right, ans);
        if(ans == -1) ans = -1;
        if(abs(lh-rh) > 1) ans = -1;
        return 1 + max(lh,rh);
    }
public:
    bool isBalanced(TreeNode* root) {
        int ans = 1;
        solve(root,ans);
        return ans == -1? false: true;
    }
};
