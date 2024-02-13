class Solution {
public:
    void mark(int x, int y, vector<vector<char>>& board){
        if ( x < 0 || x >= board.size() || y < 0 || y >= board[0].size() || board[x][y] == '0'|| board[x][y] == 'X'){
            return;
        }
        board[x][y] = 'X';
        mark(x+1,y, board);
        mark(x-1,y, board);
        mark(x,y+1, board);
        mark(x,y-1, board);
    }
    int numIslands(vector<vector<char>>& grid) {
        int ans = 0;
        for (int i = 0; i  < grid.size(); i++){
            for (int j = 0; j < grid[0].size(); j++){
                if (grid[i][j] == '1'){
                    mark(i, j, grid);
                    ans++;
                }
            }
        }
        return ans;
    }
};