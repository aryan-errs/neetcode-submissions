class Solution:
    def isSafe(self, row: int, col: int, board: List[str]) -> bool:
        # Check the column
        for i in range(row):
            if board[i][col] == 'Q':
                return False
        
        # Check the upper right diagonal
        r, c = row, col
        while r >= 0 and c < len(board):
            if board[r][c] == 'Q':
                return False
            r -= 1
            c += 1
        
        # Check the upper left diagonal
        r, c = row, col
        while r >= 0 and c >= 0:
            if board[r][c] == 'Q':
                return False
            r -= 1
            c -= 1
        
        return True

    def solve(self, row: int, n: int, board: List[str], ans: List[List[str]]):
        if row >= n:
            ans.append(board[:])
            return
        
        for col in range(n):
            if self.isSafe(row, col, board):
                board[row] = board[row][:col] + 'Q' + board[row][col + 1:]
                self.solve(row + 1, n, board, ans)
                board[row] = board[row][:col] + '.' + board[row][col + 1:]

    def solveNQueens(self, n: int) -> List[List[str]]:
        ans = []
        board = ['.' * n for _ in range(n)]
        self.solve(0, n, board, ans)
        return ans