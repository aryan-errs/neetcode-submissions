class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<double,pair<int,int>>> pq;
        for(int i = 0; i < points.size(); i++){
            double d = sqrt((points[i][0]*points[i][0] + points[i][1]*points[i][1]));
            if(pq.size() >= k){
                if(pq.top().first > d){
                    pq.pop();
                    pq.push({d,{points[i][0], points[i][1]}});
                }
            }
            else pq.push({d,{points[i][0], points[i][1]}});
        }
        vector<vector<int>> ans;
        while(!pq.empty()){
            vector<int> tmp;
            tmp.push_back(pq.top().second.first);
            tmp.push_back(pq.top().second.second);
            pq.pop();
            ans.push_back(tmp);
        }
        return ans;
    }
};
