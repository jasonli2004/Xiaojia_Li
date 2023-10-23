class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        int len = strs.size();
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
        for (int i = 1; i <= len; i++){
            int zeros = count(strs[i-1].begin(), strs[i-1].end(),'0');
            int ones = strs[i-1].length() - zeros;
            for (int p = m; p >= zeros; p--){
                for (int q = n; q >= ones; q--){
                    dp[p][q] = max(dp[p][q], dp[p - zeros][q-ones] + 1);
                }
            }
        }
        return dp[m][n];
    }
};