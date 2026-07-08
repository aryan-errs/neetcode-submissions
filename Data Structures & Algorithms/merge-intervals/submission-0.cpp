class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> res;
        for (auto interval: intervals) {
            if (res.size() == 0) res.push_back(interval);
            else {
                vector<int> lastInterval = res[res.size()-1];
                if (interval[0] <= lastInterval[1]) {
                    res.pop_back();
                    res.push_back({
                        min(interval[0], lastInterval[0]), max(interval[1], lastInterval[1])
                    });
                } else {
                    res.push_back(interval);
                }
            }
        }
        return res;
    }
};
