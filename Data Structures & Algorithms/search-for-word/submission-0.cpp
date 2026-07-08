class Solution {
public:
    bool solve(int row, int col, int index, string word, vector<vector<char>> board){
        if(index >= word.length()) return true;
        if(row < 0 || col < 0 || row >= board.size() || col >= board[0].size() || board[row][col] != word[index]) return false;
        int n = board.size(), m = board[0].size();
        int delRow[] = {-1, 0, 1, 0};
        int delCol[] = {0, -1, 0, 1};
        char original = board[row][col];
        board[row][col] = '!';
        for(int i = 0; i < 4; i++){
            int nrow = row + delRow[i];
            int ncol = col + delCol[i];
            if(solve(nrow, ncol, index+1, word, board)) return true;
        } 
        board[row][col]= original;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size(), m = board[0].size();
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(board[i][j] == word[0]){
                    if(solve(i, j, 0, word, board)) return true;
                }
            }
        }
        return false;
    }
};
