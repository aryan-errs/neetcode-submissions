class Solution {
public:
    int solve(int index, int target, vector<int> &nums, map<int,map<int,int>> &dp) {
        if (index == nums.size()) {
            return target == 0;
        }
        if (dp.contains(index) && dp[index].contains(target)) return dp[index][target];
        dp[index][target] = solve(index+1, target - nums[index], nums, dp) + solve(index + 1, target+nums[index], nums, dp);
        return dp[index][target];

    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        map<int, map<int,int>> dp;
        return solve(0, target, nums, dp);
    }
};
