class Solution {
public:
    int solve(vector<int>& nums, int start, int end){
        int prev = nums[start];
        int prev2 = 0;
        for(int i  = start+1; i < end; i++){
            int take = nums[i];
            if(i > start+1) take += prev2;
            int notake = prev;
            int curr = max(take, notake);
            prev2 = prev;
            prev = curr;
        }
        return prev;
    }
    int rob(vector<int>& nums) {
        int a1 = solve(nums, 0, nums.size()-1);
        int a2 = solve(nums, 1, nums.size());
        return max(a1,a2);
    }
};
