class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int hare = 0, tort = 0;
        while(true){
            tort = nums[tort];
            hare = nums[nums[hare]];
            if(hare == tort) break;
        }
        tort = 0;
        while(hare!=tort){
            tort = nums[tort];
            hare = nums[hare];
        }
        return tort;
    }
};
