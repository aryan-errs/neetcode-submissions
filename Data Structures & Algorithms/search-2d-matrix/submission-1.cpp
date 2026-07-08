class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
       int n = matrix.size();
       int m = matrix[0].size();
       int top = 0, bot = n-1;
       while(top <= bot){
            int row = (top + bot)/2;
            if(target > matrix[row][m-1]){
                top = row + 1;
            }else if(target < matrix[row][0]){
                bot = row - 1;
            }else break;
       }
       if(top > bot) return false;
       int row = (top + bot)/2;
       int l = 0, h = m-1;
       while(l <= h){
            int mid = (l+h)/2;
            if(matrix[row][mid] == target) return true;
            else if(matrix[row][mid] < target) l = mid + 1;
            else h = mid - 1;
       }
       return false;
    }
};
