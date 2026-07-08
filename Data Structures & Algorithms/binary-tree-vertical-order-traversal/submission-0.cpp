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
    vector<vector<int>> verticalOrder(TreeNode* root) {
        map<int, vector<int>> mp;
        queue<pair<int,TreeNode*>> q;
        if(root){
            q.push({0, root});
        }
        while(!q.empty()){
            pair<int,TreeNode*> top = q.front();
            q.pop();
            mp[top.first].push_back(top.second->val);
            if(top.second->left){
                q.push({top.first-1, top.second->left});
            }
            if(top.second->right){
                q.push({top.first+1, top.second->right});
            }
        }
        vector<vector<int>> ans;
        for(auto it: mp){
            ans.push_back(it.second);
        }
        return ans;
    }
};