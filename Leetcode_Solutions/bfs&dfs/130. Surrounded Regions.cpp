class Solution {
public:
    void mark(int x, int y, vector<vector<char>>& board, vector<vector<int>>& visited){
        if ( x < 0 || x >= board.size() || y < 0 || y >= board[0].size() || visited[x][y] == 1 || board[x][y] == 'X'){
            return;
        }
        visited[x][y] = 1;
        mark(x+1,y, board, visited);
        mark(x-1,y, board, visited);
        mark(x,y+1, board, visited);
        mark(x,y-1, board, visited);
    }
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        vector<vector<int>> visited(201, vector<int>(201, 0));
        for (int i = 0; i < n; i++){
            if (board[0][i] == 'O'){
                mark(0,i,board,visited);
            }
            if (board[m-1][i] =='O'){
                mark(m-1,i,board, visited);
            }
        }
        for (int i = 0; i < m; i++){
            if (board[i][0] == 'O'){
                mark(i,0,board,visited);
            }
            if (board[i][n-1] =='O'){
                mark(i,n-1,board, visited);
            }
        }
        for (int i = 1; i < m-1; i++){
            for (int j = 1; j < n-1; j++){
                if (visited[i][j] == 0){
                    board[i][j] = 'X';
                }
            }
        }
        return;
    }
};