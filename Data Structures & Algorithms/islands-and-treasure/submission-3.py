class Solution:
    def islandsAndTreasure(self, grid: List[List[int]]) -> None:
        delr = [0, -1, 0, 1]
        delc = [-1, 0, 1, 0]
        q = deque()
        ROWS, COLS = len(grid), len(grid[0])
        for i in range(ROWS):
            for j in range(COLS):
                if grid[i][j] == 0:
                    q.append((0,i,j))
        while q:
            d, x, y = q.popleft()
            for i in range(4):
                nr = x + delr[i]
                nc = y + delc[i]
                if 0 <= nr < ROWS and 0 <= nc < COLS and grid[nr][nc] != -1 and grid[nr][nc] > 1 + d:
                    grid[nr][nc] = 1 + d
                    q.append((1+d, nr, nc))