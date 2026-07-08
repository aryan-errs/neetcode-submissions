class Solution {
public:
    void bfs(vector<vector<int>>&grid, int row, int col){
        int n = grid.size();
        int m = grid[0].size();
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> pq;
        pq.push({0, {row, col}});
        int delRow[] = {-1, 0, 1, 0};
        int delCol[] = {0, -1, 0, 1};
        while(!pq.empty()){
            int currD = pq.top().first;
            int x = pq.top().second.first;
            int y = pq.top().second.second;
            pq.pop();
            for(int i = 0; i < 4; i++){
                int nrow = x + delRow[i];
                int ncol = y + delCol[i];
                if(nrow >= 0 && ncol >= 0 && nrow < n && ncol < m && grid[nrow][ncol] != -1){
                    if(grid[nrow][ncol] > currD+1){
                        grid[nrow][ncol] = currD+1;
                        pq.push({grid[nrow][ncol], {nrow, ncol}});
                    }
                }
            }
        }
    }
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 0){
                    bfs(grid, i, j);
                }
            }
        }
    }
};
