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
    vector<vector<int>> levelOrder(TreeNode* root) {
        deque<TreeNode*> q;
        if(root) q.push_back(root);
        vector<vector<int>> ans;
        while(!q.empty()){
            vector<int> temp;
            int sz = q.size();
            for(int i = 0; i < sz; i++){
                TreeNode* node = q.front();
                q.pop_front();
                temp.push_back(node->val);
                if(node->left) q.push_back(node->left);
                if(node->right) q.push_back(node->right);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};
