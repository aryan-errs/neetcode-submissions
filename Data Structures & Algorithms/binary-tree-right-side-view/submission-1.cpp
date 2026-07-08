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
    vector<int> rightSideView(TreeNode* root) {
        map<int,int> mp;
        deque<pair<TreeNode*,int>> q;
        if(root) q.push_back({root, 0});
        while(!q.empty()){
            int level = q.front().second;
            TreeNode* node = q.front().first;
            mp[level] = node->val;
            q.pop_front();
            if(node->left) q.push_back({node->left, level+1});
            if(node->right) q.push_back({node->right, level+1});
        }
        vector<int> ans;
        for(auto it: mp){
            ans.push_back(it.second);
        }
        return ans;
    }
};
