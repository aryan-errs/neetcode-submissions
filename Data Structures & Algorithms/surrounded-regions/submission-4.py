class Solution:
    def solve(self, board: List[List[str]]) -> None:
        n,m = len(board), len(board[0])
        q = []
        # vis = [[False for _ in range(m)] for _ in range(n)]
        for i in range(n):
            if board[i][0] == 'O':
                q.append((i,0))
                board[i][0] = 'T'
            if board[i][m-1] == 'O':
                q.append((i,m-1))
                board[i][m-1] = 'T'

        for i in range(m):
            if board[0][i] == 'O':
                q.append((0,i))
                board[0][i] = 'T'
            if board[n-1][i] == 'O':
                q.append((n-1,i))
                board[n-1][i] = 'T'
        
        delr = [-1, 0, 1, 0]
        delc = [0, -1, 0, 1]

        while q:
            x,y = q.pop(0)
            for i in range(4):
                nrow, ncol = x + delr[i], y + delc[i]
                if 0 <= nrow < n and 0 <= ncol < m and board[nrow][ncol] == 'O':
                    board[nrow][ncol] = 'T'
                    q.append((nrow, ncol))

        for i in range(n):
            for j in range(m):
                if board[i][j] == 'O':
                    board[i][j] = 'X'
        for i in range(n):
            for j in range(m):
                if board[i][j] == 'T':
                    board[i][j] = 'O'
            
        