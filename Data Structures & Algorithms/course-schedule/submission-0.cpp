class Solution {
public:

    bool canFinish(int n, vector<vector<int>>& c) {
        vector<int> adj[n];
        vector<int> incoming(n, 0);
        for(auto it: c){
            adj[it[0]].push_back(it[1]);
            incoming[it[1]]++;
        }
        queue<int> q;
        for(int i = 0; i < n; i++){
            if(incoming[i] == 0) q.push(i);
        }
        int cnt= 0;
        while(!q.empty()){
            int course = q.front();
            q.pop();
            cnt++;
            for(auto it: adj[course]){
                incoming[it]--;
                if(incoming[it] == 0){
                    q.push(it);
                }
            }
        }
        return cnt == n;

    }
};
