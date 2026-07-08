#define pb push_back
class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& p) {
        vector<int> adj[n];
        vector<int> indegree(n, 0);
        for(auto it: p){
            adj[it[1]].pb(it[0]);
            indegree[it[0]]++;
        }
        int cnt = 0;
        queue<int> q;
        for(int i = 0; i < n; i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }
        while(!q.empty()){
            int curr = q.front();
            q.pop();
            cnt++;
            for(auto it: adj[curr]){
                indegree[it]--;
                if(indegree[it] == 0) q.push(it);
            }
        }
        return cnt == n;
    }
};
