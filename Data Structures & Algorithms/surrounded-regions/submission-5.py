class Solution:
    def solve(self, board: List[List[str]]) -> None:
        q = deque()
        n, m = len(board), len(board[0])
        vis = [[0 for _ in range(m)] for _ in range(n)]
        for i in range(m):
            if board[0][i] == 'O' and not vis[0][i]:
                q.append((0,i))
                vis[0][i] = 1
            if board[n-1][i] == 'O' and not vis[n-1][i]:
                q.append((n-1,i))
                vis[n-1][i] = 1
        for i in range(1,n-1):
            if board[i][0] == 'O' and not vis[i][0]:
                q.append((i,0))
                vis[i][0] = 1
            if board[i][m-1] == 'O' and not vis[i][m-1]:
                q.append((i,m-1))
                vis[i][m-1] = 1
        delr = [-1, 0, 1, 0]
        delc = [0, -1, 0, 1]
        while q:
            x, y = q.popleft()
            for i in range(4):
                nr = x + delr[i]
                nc = y + delc[i]
                if 0 <= nr < n and 0 <= nc < m and board[nr][nc] == 'O' and not vis[nr][nc]:
                    q.append((nr,nc))
                    vis[nr][nc] = 1
        for i in range(n):
            for j in range(m):
                if board[i][j] == 'O' and not vis[i][j]:
                    board[i][j] = 'X'