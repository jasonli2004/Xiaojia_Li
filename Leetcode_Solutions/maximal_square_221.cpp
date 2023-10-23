class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int row = matrix.size();
        int col = matrix[0].size();
        vector<vector<int>> grid(row, vector<int>(col, 0));
        int maxsize = 0;  // track the maximum size as we go

        for (int i = 0; i < row; i++){
            for (int j = 0; j < col; j++){
                if (i == 0 || j == 0 || matrix[i][j] == '0'){
                    grid[i][j] = (int) (matrix[i][j] == '1');
                }
                else{
                    int minsize = min(grid[i-1][j], grid[i][j-1]);
                    if (minsize == 0){
                        grid[i][j] = 1;
                    }
                    else{
                        if (matrix[i-minsize][j-minsize] == '1'){
                            grid[i][j] = minsize + 1;
                        }
                        else{
                            grid[i][j] = minsize;
                        }
                    }
                }
                maxsize = max(maxsize, grid[i][j]);
            }
        }
        return maxsize*maxsize;
    }
};

---------------------------version2-------------------------------------
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int row = matrix.size();
        int col = matrix[0].size();
        vector<vector<int>> grid(row, vector<int>(col, 0));
        int maxsize = 0;  // track the maximum size as we go
        for (int i = 0; i < row; i++){
            for (int j = 0; j < col; j++){
                if (i == 0 || j == 0 || matrix[i][j] == '0'){
                    grid[i][j] = (int) (matrix[i][j] == '1');
                    maxsize = max(maxsize, grid[i][j]);
                    continue;
                }
                if (matrix[i][j] == '1'){
                    grid[i][j] = min(grid[i-1][j-1],min(grid[i-1][j], grid[i][j-1])) + 1;
                }
                maxsize = max(maxsize, grid[i][j]);
            }
        }
        return maxsize*maxsize;
    }
};
