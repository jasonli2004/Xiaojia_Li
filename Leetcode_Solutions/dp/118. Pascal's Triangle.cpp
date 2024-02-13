class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        vector<int> cur;
        cur.push_back(1);
        ans.push_back(cur);
        cur.clear();
        for(int i = 2; i <= numRows; i++){
            for (int j = 0; j <= i - 2; j++){
                if (j == 0){
                    cur.push_back(ans[i - 2][0]);
                    continue;
                }
                cur.push_back(ans[i - 2][j-1]+ans[i - 2][j]);
            }
            cur.push_back(ans[i - 2][i - 2]);
            ans.push_back(cur);
            cur.clear();
        }
        return ans;
    }
};