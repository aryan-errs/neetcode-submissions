class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        int prev = 0;
        int curr = nums[0];
        for(int i = 1; i < n; i++){
            int pick = nums[i];
            if(i > 1) pick += prev;
            int noPick = curr;
            int temp = max(pick, noPick);
            prev = curr;
            curr = temp;
        }
        return curr;
    }
};
