class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<pair<int,int>> adj[n];
        for(auto it: flights){
            adj[it[0]].push_back({it[1], it[2]});
        }
        vector<int> prices(n, 1e9);
        prices[src] = 0;
        queue<pair<int,int>> q;
        q.push({0, src});
        while(!q.empty()){
            int steps = q.front().first;
            int curr = q.front().second;
            q.pop();
            for(auto it: adj[curr]){
                if(prices[curr] + it.second < prices[it.first]){
                    if(steps + 1 <= k + 1 && it.first == dst){
                        q.push({steps+1, it.first});
                        prices[it.first] = prices[curr] + it.second;
                    }
                    else if(steps + 1 <= k){
                        q.push({steps+1, it.first});
                        prices[it.first] = prices[curr] + it.second;
                    }
                }
            }
        }
        return prices[dst] == 1e9? -1 : prices[dst];
    }
};
