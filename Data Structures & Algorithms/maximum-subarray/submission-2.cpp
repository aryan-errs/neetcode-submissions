class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans = INT_MIN;
        for (int i = 0; i < nums.size(); i++) {
            int currSum = 0;
            for (int j = i; j < nums.size(); j++) {
                currSum += nums[j];
                ans = max(ans, currSum);
            }
        }
        return ans;
    }
};
