class Solution:
    def solve(self, board: List[List[str]]) -> None:
        n,m = len(board), len(board[0])
        q = []
        vis = [[False for _ in range(m)] for _ in range(n)]
        for i in range(n):
            if board[i][0] == 'O' and not vis[i][0]:
                q.append((i,0))
                vis[i][0] = True
            if board[i][m-1] == 'O' and not vis[i][m-1]:
                q.append((i,m-1))
                vis[i][m-1] = True

        for i in range(m):
            if board[0][i] == 'O' and not vis[0][i]:
                q.append((0,i))
                vis[0][i] = True
            if board[n-1][i] == 'O' and not vis[n-1][i]:
                q.append((n-1,i))
                vis[n-1][i] = True
        
        delr = [-1, 0, 1, 0]
        delc = [0, -1, 0, 1]

        while q:
            x,y = q.pop(0)
            for i in range(4):
                nrow, ncol = x + delr[i], y + delc[i]
                if 0 <= nrow < n and 0 <= ncol < m and board[nrow][ncol] == 'O' and not vis[nrow][ncol]:
                    vis[nrow][ncol] = True
                    q.append((nrow, ncol))

        for i in range(n):
            for j in range(m):
                if board[i][j] == 'O' and not vis[i][j]:
                    board[i][j] = 'X'
            
        