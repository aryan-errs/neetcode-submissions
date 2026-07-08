class Solution:
    def isSafe(self, row: int, col: int, board: List[List[str]]) -> bool:
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

    def solve(self, row: int, n: int, board: List[List[str]], ans: List[List[str]]):
        if row >= n:
            # Add a copy of the board's current state to ans
            ans.append([''.join(row) for row in board])
            return
        
        for col in range(n):
            if self.isSafe(row, col, board):
                board[row][col] = 'Q'
                self.solve(row + 1, n, board, ans)
                board[row][col] = '.'

    def solveNQueens(self, n: int) -> List[List[str]]:
        ans = []
        board = [['.' for _ in range(n)] for _ in range(n)]
        self.solve(0, n, board, ans)
        return ans




        