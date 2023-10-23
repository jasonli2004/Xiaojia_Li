class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int row = mat.size();
        int col = mat[0].size();
        int updown;
        int lr;
        vector<vector<int>> grid(row, vector<int>(col, 10000000));
        for (int i = 0; i < row; i++){
            for (int j = 0; j < col; j++){
                if (!mat[i][j]){
                    grid[i][j] = 0;
                    continue;
                }
                if (i == 0 && j == 0){
                    continue;
                }
                if (i > 0){
                    updown = grid[i-1][j];
                }
                else{
                    updown = 10000000;
                }
                if (j > 0){
                    lr = grid[i][j-1];
                }
                else{
                    lr = 10000000;
                }
                grid[i][j] = min(updown, lr) + 1;
            }
        }
        for (int i = row - 1; i >= 0; i--){
            for (int j = col - 1; j >= 0; j--){
                if (!mat[i][j]){
                    grid[i][j] = 0;
                    continue;
                }
                if (i == row - 1 && j == col - 1){
                    continue;
                }
                if (i < row - 1){
                    updown = grid[i+1][j];
                }
                else{
                    updown = 10000000;
                }
                if (j < col - 1){
                    lr = grid[i][j+1];
                }
                else{
                    lr = 10000000;
                }
                grid[i][j] = min(grid[i][j], min(updown, lr) + 1) ;
            }
        }  
        return grid;
    }
};