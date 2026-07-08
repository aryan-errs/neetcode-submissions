class Solution {
public:
    void bfs(int node, vector<int>& vis, vector<int> adj[]){
        vis[node] = 1;
        queue<int> q;
        q.push(node);
        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            for (auto it: adj[curr]) {
                if (!vis[it]) {
                    q.push(it);
                    vis[it] = 1;
                }
            }
        }
    }
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<int> adj[n];
        for (int i = 0; i < edges.size(); i++) {
            int a = edges[i][0], b = edges[i][1];
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        vector<int> vis(n, 0);
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                cnt += 1;
                bfs(i, vis, adj);
            }
        }
        return cnt;
    }
};
