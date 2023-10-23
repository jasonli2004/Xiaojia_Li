class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<int>> ans;
        int m = heights.size();
        int n = heights[0].size();
        if (m == 0 || n == 0){
            return {};
        }
        vector<vector<bool>> can_reach_a(m, vector<bool>(n, false));
        vector<vector<bool>> can_reach_p(m, vector<bool>(n, false));
        for (int i = 0; i < m; i++){
            dfs(heights, i, 0, can_reach_p);
            dfs(heights, i, n - 1, can_reach_a);
        }
        for (int i = 0; i < n; i++){
            dfs(heights, 0, i, can_reach_p);
            dfs(heights, m - 1, i, can_reach_a);
        }
        for (int i = 0; i < m; i++){
            for (int j = 0; j < n; j++){
                if (can_reach_a[i][j] && can_reach_p[i][j]){
                    
                    ans.push_back(vector<int>{i, j});
                }
            }
        }
        return ans;
    }

    void dfs(vector<vector<int>>& heights, int i, int j, vector<vector<bool>>& reachable){
        int num = heights[i][j];
        reachable[i][j] = true;
        if ( i + 1 < heights.size() &&  num <= heights[i+1][j] && !reachable[i+1][j]){
            dfs(heights, i + 1, j, reachable);
        }
        if ( i - 1 >= 0 && num <= heights[i-1][j]  && !reachable[i-1][j]){
            dfs(heights, i - 1, j, reachable);
        }
        if ( j + 1 < heights[0].size() && num <= heights[i][j+1] && !reachable[i][j+1]){
            dfs(heights, i , j + 1, reachable);
        }
        if ( j - 1 >= 0 && num <= heights[i][j-1]  && !reachable[i][j-1]){
            dfs(heights, i, j - 1, reachable);
        }
    }
};