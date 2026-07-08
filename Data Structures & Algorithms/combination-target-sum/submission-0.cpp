class Solution {
public:
    void solve(int index, int sum, int target, vector<int> nums, vector<int> &temp, vector<vector<int>> &ans){
        if(sum == target){
            ans.push_back(temp);
            return;
        }
        if(sum > target) return;
        for(int i = index; i < nums.size(); i++){
            temp.push_back(nums[i]);
            solve(i,sum+nums[i], target, nums, temp,ans);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int>temp;
        vector<vector<int>> ans;
        solve(0,0,target,nums,temp,ans);
        return ans;
    }
};
