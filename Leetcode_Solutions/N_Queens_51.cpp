class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n, string(n, '.'));
        vector<bool> col(n, false), ldiag(2*n-1, false), rdiag(2*n-1, false);
        backtrack(ans, board, col, ldiag, rdiag, 0, n);
        return ans;
    }
    void backtrack(vector<vector<string>>& ans, vector<string>& board, vector<bool>& col, vector<bool> ldiag, vector<bool> rdiag, int row, int n){
        if (row == n){
            ans.push_back(board);
        }
        for (int i = 0; i < n; i++){
            if (col[i] || ldiag[row+i] || rdiag[n - i +row - 1]){
                continue;
            }
            board[row][i] = 'Q';
            col[i] = ldiag[row+i] = rdiag[n - i +row - 1] = true;
            backtrack(ans, board, col, ldiag, rdiag, row + 1, n);
            board[row][i] = '.';
            col[i] = ldiag[row+i] = rdiag[n - i +row - 1] = false;
        }
    }
};