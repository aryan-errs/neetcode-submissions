class Solution {
public:
    set<vector<int>> st;
    void solve(int index, vector<int> temp, vector<int> nums) {
        if (index == nums.size()) {
            st.insert(temp);
            return;
        }
        temp.push_back(nums[index]);
        solve(index+1, temp, nums);
        temp.pop_back();
        solve(index+1, temp, nums);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        solve(0, {}, nums);
        vector<vector<int>> ans(st.begin(), st.end());
        return ans;
    }
};
