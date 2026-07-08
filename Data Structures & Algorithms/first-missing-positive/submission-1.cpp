class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i]-1 != i) {
                if (nums[i]-1 >= 0 && nums[i]-1 < nums.size()) {
                    swap(nums[nums[i]-1], nums[i]);
                }
            }
        }
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i]-1 != i) {
                if (nums[i]-1 >= 0 && nums[i]-1 < nums.size()) {
                    swap(nums[nums[i]-1], nums[i]);
                }
            }
        }
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            if (nums[i]-1 != i) return i+1;
        }
        return n+1;
    }
};