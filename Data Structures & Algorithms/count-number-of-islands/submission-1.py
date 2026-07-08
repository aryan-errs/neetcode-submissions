class Solution:
    def bfs(self, row:int, col:int, grid:List[List[str]]):
        q = [(row,col)]
        n,m = len(grid), len(grid[0])
        delr = [-1,0,1,0]
        delc = [0,-1,0,1]
        while q:
            x,y = q.pop(0)
            for i in range(4):
                nrow, ncol = x + delr[i], y + delc[i]
                if nrow >= 0 and ncol >= 0 and nrow < n and ncol < m and grid[nrow][ncol] == '1':
                    grid[nrow][ncol] = '0'
                    q.append((nrow,ncol))

    def numIslands(self, grid: List[List[str]]) -> int:
        cnt = 0
        n,m = len(grid), len(grid[0])
        for i in range(n):
            for j in range(m):
                if grid[i][j] == '1':
                    cnt += 1
                    self.bfs(i,j,grid)
        return cnt