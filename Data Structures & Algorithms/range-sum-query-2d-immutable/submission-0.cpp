class NumMatrix {
    vector<vector<int>> preSum;
    int row, col;
public:
    NumMatrix(vector<vector<int>>& matrix) {
        this->row = matrix.size();
        this->col = matrix[0].size();
        preSum.resize(this->row, vector<int>(this->col));
        for(int i = 0; i < this->row; i++) {
            for (int j = 0; j < this->col; j++) {
                this->preSum[i][j] = matrix[i][j];
                if (j > 0) {
                    this->preSum[i][j] += this->preSum[i][j-1];
                }
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int sum = 0;
        for (int i = row1; i <= row2; i++) {
            if (col1 == 0) {
                sum += this->preSum[i][col2];
            } else {
                sum += this->preSum[i][col2] - this->preSum[i][col1-1];
            }
        }
        return sum;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */