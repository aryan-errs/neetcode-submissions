class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = 0 , ans = INT_MIN, n = nums.size();
        int maxNeg = INT_MIN;
        for(int i = 0; i < n; i++){
            sum += nums[i];
            if(sum < 0){
                maxNeg = max(maxNeg, sum);
                sum = 0;
            }
            else{
                ans = max(ans, sum);
            }
        }
        return ans == INT_MIN? maxNeg: ans;
    }
};
