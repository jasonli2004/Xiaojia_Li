class Solution {
public:
    int maximalSquare(vector<vector<char>>& original) {
        int row = original.size();
        int col = original[0].size();
        vector<vector<int>> matrix(row, vector<int>(col, 0));
        int cur_max = 0;
        for (int i = 0; i < row; i++){
            if (original[i][0] == '1'){
                cur_max = 1;
                matrix[i][0] = 1;
            }
            else{
                matrix[i][0] = 0;
            }
        }
        for (int i = 0; i < col; i++){
            if (original[0][i] == '1' || matrix[0][i] == 1 ){
                cur_max = 1;
                matrix[0][i] = 1;
            }
            else{
                matrix[0][i] = 0;
            }
        }
        for (int i = 1; i < row; i++){
            for (int j = 1; j < col; j++){
                if (original[i][j] == '1'){
                    matrix[i][j] = min(matrix[i][j-1], min(matrix[i-1][j], matrix[i-1][j-1])) + 1;
                    if (matrix[i][j] > cur_max){
                        cur_max = matrix[i][j];
                    }
                }
                else{
                    matrix[i][j] = 0;
                }
            }
        }
        return cur_max*cur_max;
    }
};
