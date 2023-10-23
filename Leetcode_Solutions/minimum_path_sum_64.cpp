class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        int topsum;
        int leftsum;
        for (int i = 0; i < row; i++){
            for (int j = 0; j < col; j++){
                if (i == 0 && j == 0){
                    continue;
                }
                if (i > 0){
                    topsum = grid[i-1][j];
                }
                else{
                    topsum = INT_MAX;
                }
                if (j > 0){
                    leftsum = grid[i][j-1];
                }
                else{
                    leftsum = INT_MAX;
                }
                grid[i][j] = min(leftsum, topsum) + grid[i][j];
            }
        }
        return grid[row-1][col-1];
    }
};