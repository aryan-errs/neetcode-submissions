class Solution:
    def orangesRotting(self, grid: List[List[int]]) -> int:
        delr = [-1, 0, 1, 0]
        delc = [0, -1, 0, 1]
        q = deque()
        ROWS,COLS = len(grid), len(grid[0])
        timeTaken = 0
        fresh = 0
        vis = {}
        for i in range(ROWS):
            for j in range(COLS):
                if grid[i][j] == 2:
                    q.append((0, i, j))
                    vis[(i,j)] = 1
                if grid[i][j] == 1:
                    fresh += 1
        while q:
            t, x, y = q.popleft()
            timeTaken = max(timeTaken, t)
            if grid[x][y] == 1:
                fresh -= 1
            for i in range(4):
                nr = x + delr[i]
                nc = y + delc[i]
                if 0 <= nr < ROWS and 0 <= nc < COLS and grid[nr][nc] > 0 and (nr,nc) not in vis:
                    vis[(nr,nc)] = 1
                    q.append((1 + t, nr, nc))
        print(fresh)
        return timeTaken if not fresh else -1