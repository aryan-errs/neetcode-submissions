class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int  n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        for (int i = 0; i < n; i++) {
            if (i > 0 and nums[i] == nums[i-1]) continue;
            for (int j = i + 1; j < n; j++) {
                if (j > i+1 and nums[j] == nums[j-1]) continue;
                int k = j + 1, l = n-1;
                while (k < l) {
                    long long sum = 1LL * nums[i] + nums[j] + nums[k] + nums[l];
                    if (target == sum) {
                        ans.push_back({nums[i], nums[j], nums[k], nums[l]});
                        k++;
                        while (k < l && nums[k] == nums[k-1]) k++;
                        l--;
                        while (k < l && nums[l] == nums[l+1]) l--;
                    } else if (sum > target) {
                        l--;
                        while (k < l && nums[l] == nums[l+1]) l--;
                    } else {
                        k++;
                        while (k < l && nums[k] == nums[k-1]) k++;
                    }
                }
            }
        }
        return ans;
    }
};