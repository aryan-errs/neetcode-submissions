class Solution {
public:
    int dfs(int row, int col, vector<vector<int>> &grid){
        if(row < 0 || col < 0 || row>= grid.size() || col >= grid[0].size() || !grid[row][col]){
            return 0;
        }
        grid[row][col] = 0;
        int a1 = dfs(row+1, col, grid);
        int a2 = dfs(row-1, col, grid);
        int a3 = dfs(row, col+1, grid);
        int a4 = dfs(row, col-1, grid);
        return 1+a1+a2+a3+a4;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxi = INT_MIN;
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(grid[i][j]){
                    maxi = max(maxi, dfs(i,j,grid));
                }
            }
        }
        return maxi == INT_MIN? 0: maxi;
    }
};
