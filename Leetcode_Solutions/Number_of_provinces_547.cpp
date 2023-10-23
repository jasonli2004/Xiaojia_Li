class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int cnt = 0;
        for (int i = 0; i < isConnected.size(); i++){
            if (isConnected[i][i] == 1){
                dfs(isConnected, i);
                cnt++;
            }
        }
        return cnt;
    }

    void dfs(vector<vector<int>>& isConnected, int num){
        isConnected[num][num] = 0;
        for (int i = 0; i < isConnected.size(); i++){
            if (isConnected[num][i] == 1 && isConnected[i][i] == 1 ){
                dfs(isConnected, i);
            }
        }
    }
};