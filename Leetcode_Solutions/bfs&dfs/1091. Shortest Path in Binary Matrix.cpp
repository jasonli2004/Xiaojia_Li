class Solution {
public:
    bool valid_cell(int row, int col, vector<vector<int>>& grid){
        if (row < 0 || row >= grid.size() || col < 0 || col >= grid[0].size() || grid[row][col] == 1){
            return false;
        }
        return true;
    }
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if (grid[0][0] == 1 || grid[n-1][n-1] == 1){
            return -1;
        }
        if (n == 1){
            return true;
        }
        queue<int> cnt;
        queue<pair<int, int>> q;
        q.push(make_pair(0,0));
        cnt.push(1);
        while (!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            int cur_cnt = cnt.front();
            for (int i = -1; i <= 1; i++){
                for (int j = -1; j <= 1; j++){
                    if (i != 0 || j != 0){
                        if (valid_cell(row+i, col+j, grid)){
                            if (row+i == n - 1 && col + j == n-1){
                                return cur_cnt+1;
                            }
                            q.push(make_pair(row+i, col + j));
                            cnt.push(cur_cnt+1);
                            grid[row+i][col+j] = 1;
                        }
                    }
                }
            }
            q.pop();
            cnt.pop();
        }
        return -1;
        
    }
};