class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        intervals.push_back(newInterval);
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> res;
        for(auto interval: intervals) {
            if (res.size() == 0) res.push_back(interval);
            else {
                vector<int> lastInterval = res[res.size()-1];
                if (lastInterval[1] < interval[0]) {
                    res.push_back(interval);
                } else if (lastInterval[1] >= interval[0]) {
                    res.pop_back();
                    res.push_back({
                        min(lastInterval[0], interval[0]), max(lastInterval[1], interval[1])
                    });
                }
            }
        }
        return res;
    }
};