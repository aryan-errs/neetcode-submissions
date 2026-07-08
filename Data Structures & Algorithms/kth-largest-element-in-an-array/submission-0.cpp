class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        map<int,int> mp;
        for(int i = 0; i < nums.size(); i++){
            mp[nums[i]]++;
        }
        k = nums.size() - k;
        for(auto it: mp){
            if(it.second > k) return it.first;
            k -= it.second;
        }
        return -1;
    }
};
