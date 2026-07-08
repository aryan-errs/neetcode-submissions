class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<pair<int,int>> adj[n+1];
        for (auto time: times) {
            adj[time[0]].push_back({time[1], time[2]});
        }
        vector<int> time(n+1, 1e9);
        time[k] = 0;
        priority_queue<pair<int,int>> pq;
        pq.push({0,k});
        while (!pq.empty()) {
            int t = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            for (auto it: adj[node]) {
                if (time[it.first] > t + it.second) {
                    time[it.first] = t + it.second;
                    pq.push({t+it.second, it.first});
                }
            }
        }
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            if (time[i] == 1e9) return -1;
            ans = max(ans, time[i]);
        }
        return ans;
    }
};
