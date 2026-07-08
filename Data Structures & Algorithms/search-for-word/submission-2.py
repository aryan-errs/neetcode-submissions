class Solution:
    def solve(self, row:int, col:int, index:int, word:str, board:list[list[str]]) -> bool:
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
            if self.solve(nrow, ncol, index+1, word, board):
                return True
        board[row][col] = c
        return False
    def exist(self, board: list[list[str]], word: str) -> bool:
        n,m = len(board), len(board[0])
        for i in range(0,n):
            for j in range(0, m):
                if self.solve(i,j,0,word,board):
                    return True
        return False
    
