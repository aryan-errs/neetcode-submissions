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
public:
    void traverse(TreeNode* root, int &cnt, int maxEl){
        if(!root) return;
        if(root->val >= maxEl){
            cnt++;
            maxEl = root->val;
        }
        traverse(root->left, cnt, maxEl);
        traverse(root->right, cnt, maxEl);
    }
    int goodNodes(TreeNode* root) {
        int cnt = 0, maxEl = INT_MIN;
        traverse(root, cnt, maxEl);
        return cnt;
    }
};
