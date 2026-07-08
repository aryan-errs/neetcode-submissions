class Solution {
public:
    bool canJump(vector<int>& nums) {
        vector<int> dp(nums.size(), 0);
        dp[nums.size()-1] = 1;
        for (int i = nums.size()-2; i >= 0; i--) {
            if (nums[i] == 0) continue;
            for (int j = 1; j <= nums[i]; j++) {
                if (i + j < nums.size()) {
                    dp[i] = dp[i] || dp[i+j];
                }
            }
        }
        return dp[0];
    }
};
