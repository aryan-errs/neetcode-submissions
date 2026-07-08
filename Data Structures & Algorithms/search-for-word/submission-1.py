class Solution:
    def exist(self, board: List[List[str]], word: str) -> bool:
        def solve(row:int, col:int, index:int, word:int, board:List[List[str]]) -> bool:
            if index >= len(word): 
                return True
            if row < 0 or col < 0 or row >= len(board) or col >= len(board[0]) or board[row][col] != word[index]:
                return False
            c = board[row][col]
            board[row][col] = '!'
            delr = [-1, 0, 1, 0]
            delc = [0, -1, 0, 1]
            for i in range(0,4):
                nrow = row + delr[i]
                ncol = col + delc[i]
                if solve(nrow, ncol, index+1, word, board):
                    return True
            board[row][col] = c
            return False
        
        n,m = len(board), len(board[0])
        for i in range(0,n):
            for j in range(0, m):
                if solve(i,j,0,word,board):
                    return True
        return False