class Solution {
public:
    int findMin(vector<int> &nums) {
        if(nums[0] < nums[nums.size()-1]) return nums[0];
        if(nums[nums.size()-2] > nums[nums.size()-1]) return nums[nums.size()-1];
        int l = 0, h = nums.size();
        while(l<h){
            int mid = (l+h)/2;
            if(nums[mid-1] > nums[mid] && nums[mid] < nums[mid+1]) return nums[mid];
            else if(nums[mid] > nums[0]) l = mid;
            else h = mid;
        }
        return nums[0];
    }
};
