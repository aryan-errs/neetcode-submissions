class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int tort = 0, hare = 0;
        while(true){
            tort = nums[tort];
            hare = nums[nums[hare]];
            if(hare ==tort) break;
        }
        hare = 0;
        while(hare != tort){
            tort = nums[tort];
            hare = nums[hare];
        }
        return hare;
    }
};
