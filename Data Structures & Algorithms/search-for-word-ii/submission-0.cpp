class TrieNode{
public:
    TrieNode* child[26] = {NULL};
    bool isEnd = false;
};

class Solution {
public:
    void  addWord(TrieNode* root, string word){
        if(!root) root = new TrieNode();
        TrieNode* curr = root;
        for(auto c: word){
            if(!curr->child[c-'a']){
                curr->child[c-'a'] = new TrieNode();
            }
            curr = curr->child[c-'a'];
        }
        curr->isEnd = true;
    }
    int delR[4] = {-1, 0, 1, 0};
    int delC[4] = {0, -1, 0, 1}; 
    void search(vector<vector<char>>& board, vector<string>& ans, int row, int col, TrieNode* curr, string temp){
        if(!curr) return;
        if(curr->isEnd){
            ans.push_back(temp);
            curr->isEnd = false;
        }
        char og = board[row][col];
        board[row][col] = '-';
        for(int i = 0; i < 4; i++){
            int nrow = row + delR[i];
            int ncol = col + delC[i];
            if(nrow >= 0 && ncol >= 0&& nrow < board.size() && ncol < board[0].size() && board[nrow][ncol] != '-' && curr->child[board[nrow][ncol]-'a']){
                search(board, ans, nrow, ncol, curr->child[board[nrow][ncol] - 'a'], temp + board[nrow][ncol]);                
            }
        }
        board[row][col] = og;
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<string> ans;
        TrieNode* root = new TrieNode();
        for(auto word: words){
            addWord(root, word);
        }
        int n = board.size(), m = board[0].size();
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                char ch = board[i][j];
                if(root->child[ch-'a']) search(board, ans, i, j, root->child[ch-'a'], string(1,ch));
            }
        }
        return ans;
    }
};
