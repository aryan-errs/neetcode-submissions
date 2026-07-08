class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        if (n % 2 == 1) n++;
        for (int i = 1; i < n-2; i+=2) {
            swap(nums[i], nums[i+1]);
        }
    }
};
