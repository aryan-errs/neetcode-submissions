class Solution {
public:
    bool isSafe(int row, int col, vector<string> &grid) {
        int dRow = row, dCol = col;
        while (row >= 0) {
            if (grid[row][col] == 'Q') {
                return false;
            }
            row -= 1;
        }
        row = dRow;
        while (row >= 0 && col >= 0) {
            if (grid[row][col] == 'Q') return false;
            row -= 1;
            col -= 1;
        }
        row = dRow, col = dCol;
        while (row >= 0 && col < grid.size()) {
            if (grid[row][col] == 'Q') return false;
            row -= 1;
            col += 1;
        }
        return true;
    }

    void solve(int row, int n, vector<vector<string>> &ans, vector<string> grid) {
        if (row == n) {
            ans.push_back(grid);
            return;
        }
        for (int i = 0; i < n; i++) {
            if (isSafe(row, i, grid)) {
                grid[row][i] = 'Q';
                solve(row + 1, n, ans, grid);
                grid[row][i] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> grid(n, string(n, '.'));
        solve(0, n, ans, grid);
        return ans;
    }
};
