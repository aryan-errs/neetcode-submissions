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
        if(!root) return {};
        unordered_map<int, vector<int>> mp;
        queue<pair<int,TreeNode*>> q;
        q.push({0, root});
        int min_col = 0, max_col = 0;
        while(!q.empty()){
            pair<int,TreeNode*> top = q.front();
            q.pop();
            mp[top.first].push_back(top.second->val);
            min_col = min(min_col, top.first);
            max_col = max(max_col, top.first);
            if(top.second->left){
                q.push({top.first-1, top.second->left});
            }
            if(top.second->right){
                q.push({top.first+1, top.second->right});
            }
        }
        vector<vector<int>> ans;
        for(int i = min_col; i <= max_col; i++){
            ans.push_back(mp[i]);
        }
        return ans;
    }
};