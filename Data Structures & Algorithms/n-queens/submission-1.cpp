class Solution {
public:
    bool isSafe(int col, int row, int n, vector<string> &temp){
        int dupRow = row, dupCol = col;
        while(row >= 0){
            if(temp[row][col] == 'Q') return false;
            row--;
        }
        row = dupRow;
        while(col >=0 && row >= 0){
            if(temp[row][col] == 'Q') return false;
            row--;
            col--;
        }
        row = dupRow, col = dupCol;
        while(col < n && row >= 0){
            if(temp[row][col] == 'Q') return false;
            row--;
            col++;
        }
        return true;
    }
    void helper(int row, int n, vector<string> &temp, vector<vector<string>> &ans){
        if(row == n){
            ans.push_back(temp);
            return;
        }
        for(int i = 0; i < n; i++){
            if(isSafe(i,row,n,temp)){
                temp[row][i] = 'Q';
                helper(row+1, n, temp, ans);
                temp[row][i] = '.';
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
