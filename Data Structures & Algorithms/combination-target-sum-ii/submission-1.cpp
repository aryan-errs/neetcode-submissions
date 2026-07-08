class Solution {
public:
    void solve(int index, int target, vector<int> nums, vector<int> &temp, vector<vector<int>> &ans){
        if(target == 0){
            ans.push_back(temp);
            return;
        }
        if(target < 0) return;
        for(int i = index; i < nums.size(); i++){
            if(i != index && nums[i] == nums[i-1]) continue;
            temp.push_back(nums[i]);
            solve(i+1,target-nums[i], nums, temp, ans);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& nums, int target) {
        vector<int> temp;
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        solve(0,target, nums, temp, ans);
        return ans;
    }
};
