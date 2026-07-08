class Solution {
public:
    bool solve(int x, int y, string word, vector<vector<char>> &board) {
        if (word == "") return true;
        if (x < 0 || y < 0 || x >= board.size() || y >= board[0].size() || board[x][y] == '#' || board[x][y] != word[0]) {
            return false;
        }
        char og = board[x][y];
        board[x][y] = '#';
        bool res = solve(x+1, y, word.substr(1,word.size()), board) || 
                    solve(x, y + 1, word.substr(1, word.size()), board) ||
                    solve(x-1, y, word.substr(1,word.size()), board) || 
                    solve(x, y-1, word.substr(1,word.size()), board);
        board[x][y] = og;
        return res;
    }
    bool exist(vector<vector<char>>& board, string word) {
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (board[i][j] == word[0]) {
                    if (solve (i, j, word, board)) return true;
                }
            }
        }
        return false;
    }
};
