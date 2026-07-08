class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int,pair<int,int>>> pq;
        for (auto point: points) {
            int x = point[0], y = point[1];
            int d = x*x + y*y;
            pq.push({d, {x,y}});
            if (pq.size() > k) pq.pop();
        }
        vector<vector<int>> res;
        for (int i = 0; i < k && !pq.empty(); i++) {
            pair<int,int> p = pq.top().second;
            pq.pop();
            res.push_back({p.first, p.second});
        }
        return res;
    }
};
