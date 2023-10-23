class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxarea = 0;
        for (int i = 0; i < grid.size(); i++){
            for (int j = 0; j < grid[i].size(); j++){
                if (grid[i][j] == 1){
                    int cnt = 0;
                    stack<pair<int, int>> frontier;
                    frontier.push(make_pair(i,j));
                    while(!frontier.empty()){
                        pair<int, int> temp = frontier.top();
                        int first = temp.first;
                        int second = temp.second;
                        frontier.pop();
                        grid[first][second] = 0;
                        cnt++;
                        if (first + 1 < grid.size() && grid[first+1][second] == 1){
                            frontier.push(make_pair(first+1, second));
                            grid[first+1][second] = 0;
                        }
                        if (first - 1 >= 0 && grid[first-1][second] == 1){
                            frontier.push(make_pair(first-1, second));
                            grid[first-1][second] = 0;
                        }
                        if (second + 1 < grid[0].size() && grid[first][second+1] == 1){
                            frontier.push(make_pair(first, second+1));
                            grid[first][second+1] = 0;
                        }
                        if (second - 1 >= 0 && grid[first][second-1] == 1){
                            frontier.push(make_pair(first, second-1));
                            grid[first][second-1] = 0;
                        }
                    }
                    if (cnt > maxarea){
                        maxarea = cnt;
                    }
                }
            }
        }
        return maxarea;   
    }
};