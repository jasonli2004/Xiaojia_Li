class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.length();
        vector<bool> dp(n + 1, false);
        dp[0] = true;
        for (int i = 1; i <= n; ++i){
            for ( auto word: wordDict){
                int wordlen = word.length();
                if (i >= wordlen && s.substr(i - wordlen, wordlen) == word){
                    dp[i] = dp[i] || dp[i - wordlen];
                }
            }
        }
        return dp[n];
    }
};