class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int> mp;
        for(int i = 0; i < nums.size(); i++){
            mp[nums[i]] = i + 1;
        }
        vector<int> ans(2);
        for (int i = 0; i < nums.size(); i++) {
            if (mp.contains(target-nums[i]) && mp[target-nums[i]] != i+1) {
                ans[0] = i;
                ans[1] = mp[target-nums[i]] - 1;
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};
