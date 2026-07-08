class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        int prev1 = nums[0];
        int prev2 = 0;
        for(int i = 1; i < n-1; i++){
            int pick = nums[i];
            if(i > 1) pick += prev2;
            int noPick = prev1;
            int temp = max(pick, noPick);
            prev2 = prev1;
            prev1 = temp;
        }
        int ans1 = prev1;
        prev1 = nums[1], prev2 = 0;
        for(int i = 2; i < n; i++){
            int pick = nums[i];
            if(i > 2) pick += prev2;
            int noPick = prev1;
            int temp = max(pick, noPick);
            prev2 = prev1;
            prev1 = temp;
        }
        int ans2 = prev1;
        return max(ans1, ans2);
    }
};
