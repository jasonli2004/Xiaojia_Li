class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        bool found = false;
        for (int i = 0; i < m; i++){
            for (int j = 0; j < n; j++){
                if (word[0] == board[i][j]){
                    backtrack(board, word, i, j, visited, found , 0, m, n); 
                }
                if (found){
                    return true;
                }
            }
        }
        return found;
    }

    void backtrack(vector<vector<char>>& board, string word, int i, int j, vector<vector<bool>>& visited, bool& found, int pos, int m, int n){
        if (pos == word.size() - 1){
            found = true;
            return;
        }
        visited[i][j] = true;
        if (i + 1 < m && !visited[i+1][j] && !found && word[pos+1] == board[i+1][j]){
            backtrack(board, word, i+1, j, visited, found, pos + 1, m, n);
        }
        if (i - 1 >= 0 && !visited[i-1][j] && !found && word[pos+1] == board[i-1][j]){
            backtrack(board, word, i-1, j, visited, found, pos + 1, m, n);
        }
        if (j + 1 < n && !visited[i][j+1] && !found && word[pos+1] == board[i][j+1]){
            backtrack(board, word, i, j+1, visited, found, pos + 1, m, n);
        }
        if (j - 1 >= 0 && !visited[i][j-1] && !found && word[pos+1] == board[i][j-1]){
            backtrack(board, word, i, j - 1, visited, found, pos + 1, m, n);
        }
        visited[i][j] = false;
    }
};