class Solution {
public:
    void solve(int index, vector<int> &temp, vector<int> nums, vector<vector<int>> &ans){
        if(index == nums.size()){
            ans.push_back(temp);
            return;
        }
        temp.push_back(nums[index]);
        solve(index+1, temp, nums, ans);
        temp.pop_back();
        solve(index+1, temp, nums, ans);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> temp;
        vector<vector<int>> ans;
        solve(0,temp, nums, ans);
        return ans;
    }
};
