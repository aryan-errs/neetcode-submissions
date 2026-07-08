class Solution {
public:
    // int solve(int x, int y, int m, int n, vector<vector<int>> &dp) {
    //     if (x > m-1 || y > n-1) return 0;
    //     if (x == m-1 && y == n-1) {
    //         return 1;
    //     }
    //     if (dp[x][y] != -1) return dp[x][y];
    //     dp[x][y] = solve(x+1, y, m, n, dp) + solve(x, y+1, m, n, dp);
    //     return dp[x][y];
    // }
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n,1));
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                dp[i][j] = dp[i][j-1] + dp[i-1][j];
            }
        }
        return dp[m-1][n-1];
    }
};
