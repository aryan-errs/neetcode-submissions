class Solution {
public:
    int maxProfit(vector<int>& nums) {
        int ans = 0;
        int maxEl = nums[nums.size()-1];
        for(int i = nums.size()-2; i>=0; i--){
            ans = max(ans, maxEl - nums[i]);
            if(maxEl < nums[i]) maxEl = nums[i];
        }
        return ans;
    }
};
