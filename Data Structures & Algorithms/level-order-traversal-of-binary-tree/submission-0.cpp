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
        if(!root) return vector<vector<int>> ();
        map<int,vector<int>> mp;
        queue<pair<TreeNode*,int>> q;
        q.push({root, 1});
        while(!q.empty()){
            TreeNode* node = q.front().first;
            int level = q.front().second;
            q.pop();
            mp[level].push_back(node->val);
            if(node->left != nullptr) q.push({node->left, level+1});
            if(node->right != nullptr) q.push({node->right, level+1});
        }
        vector<vector<int>> ans;
        for(auto it: mp){
            ans.push_back(it.second);
        }
        return ans;
    }
};
