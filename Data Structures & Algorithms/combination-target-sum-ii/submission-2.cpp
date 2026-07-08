class Solution {
public:
    void solve(int index, int t, vector<int> temp, vector<int> &candidates, vector<vector<int>>&ans){
        if (t < 0) return;
        if (t == 0) {
            ans.push_back(temp);
            return;
        }
        for (int i = index; i < candidates.size(); i++) {
            if (i > index && candidates[i] == candidates[i-1]) continue;
            temp.push_back(candidates[i]);
            solve(i+1, t - candidates[i], temp, candidates, ans);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> temp;
        solve(0, target, temp, candidates, ans);
        return ans;
    }
};
