class Solution {
public:
    bool isSafe(int row, int col, int n, vector<string> &temp){
        int dupRow = row, dupCol = col;
        while(col>=0){
            if(temp[row][col] == 'Q') return false;
            col--;
        }
        col = dupCol;
        while(row >= 0 && col >= 0){
            if(temp[row][col] == 'Q') return false;
            col--;
            row--;
        }
        col = dupCol, row = dupRow;
        while(row < n && col >= 0){
            if(temp[row][col] == 'Q') return false;
            col--;
            row++;
        }
        return true;
    }
    void helper(int col, int n, vector<string> &temp, vector<vector<string>> &ans){
        if(col == n){
            ans.push_back(temp);
            return;
        }
        for(int i = 0; i < n; i++){
            if(isSafe(i,col,n,temp)){
                temp[i][col] = 'Q';
                helper(col+1, n, temp, ans);
                temp[i][col] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> temp(n,string(n,'.'));
        helper(0,n,temp,ans);
        return ans;
    }
};
