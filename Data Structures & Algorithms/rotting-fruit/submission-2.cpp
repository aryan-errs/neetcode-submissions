class Solution {

public:
    int orangesRotting(vector<vector<int>>& grid) {
        int cntO = 0, n = grid.size(), m = grid[0].size();
        queue<pair<int,pair<int,int>>> q;
        vector<vector<int>> vis(n, vector<int> (m,0));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 1) cntO++;
                if(grid[i][j] == 2) q.push({0, {i,j}});
            }
        }
        int time = 0;
        int delR[] = {-1, 0, 1, 0};
        int delC[] = {0, -1, 0, 1};
        while(!q.empty()){
            int currTime = q.front().first;
            int r = q.front().second.first;
            int c = q.front().second.second;
            q.pop();
            time = max(time, currTime);
            for(int i = 0; i < 4; i++){
                int nrow = r + delR[i];
                int ncol = c + delC[i];
                if(nrow >= 0 && ncol >= 0 && nrow < grid.size() && ncol < grid[0].size() && grid[nrow][ncol] == 1 && !vis[nrow][ncol]){
                    q.push({currTime+1, {nrow, ncol}});
                    vis[nrow][ncol] = 1;
                    cntO--;
                }
            }
        }
        if(cntO) return -1;
        return time;


    }
};
