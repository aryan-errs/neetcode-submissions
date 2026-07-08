class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        vector<int> adj[n];
        // vector<int> indegree(n, 0);
        for(auto it: edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        queue<pair<int,int>> q;
        vector<int> vis(n , 0);
        vis[0] = 1;
        q.push({-1, 0});
        while(!q.empty()){
            int node = q.front().second;
            int parent = q.front().first;
            q.pop();
            
            for(int neighbor : adj[node]) {
                if(!vis[neighbor]) {
                    vis[neighbor] = 1;
                    q.push({node, neighbor});
                } else if(neighbor != parent) {
                    return false;
                }
            }
        }
        for(int i = 0; i < n; i++){
            if(!vis[i]) return false;
        }
        return true;
    }
};
