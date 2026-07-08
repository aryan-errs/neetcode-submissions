class Solution {
public:
    int rob(vector<int>& nums) {
        int prev = 0;
        int prev2 = nums[0];
        int ans = 0;
        for(int i = 1; i < nums.size(); i++){
            int take = nums[i];
            if(i > 1) take += prev;
            int noTake = prev2;
            ans = max(take, noTake);
            prev = prev2;
            prev2 = ans;
        } 
        return prev2;       
    }
};
