class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        int prev = 0;
        int curr = 0;
        for(int i = 0; i < n; i++){
            int temp = max(prev+nums[i], curr);
            prev = curr;
            curr = temp;
        }
        return curr;
    }
};
