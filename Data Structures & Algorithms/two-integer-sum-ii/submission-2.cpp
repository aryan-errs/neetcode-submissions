class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        for(int i = 0; i < n; i++){
            int num = nums[i];
            int newT = target - num;
            int low = i, high = n-1;
            while(low <= high){
                int mid = low + (high - low)/2;
                if(nums[mid] == newT and mid != i) return {i+1, mid+1};
                if(nums[mid] < newT) low = mid + 1;
                else high = mid-1;
            }
        }
        return {-1, -1};
    }
};
