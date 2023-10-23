class Solution {
#include <cstring>
public:
    int numDecodings(string s) {
        int len = s.size();
        vector<int> dp(len+1, 1);
        if (s[0] == '0'){
            return 0;
        }
        for (int i = 2; i <= len; i++){
            int temp = 0;
            string num = "";
            if (s[i-1] != '0'){
                temp += dp[i-1];
            }
            if (s[i - 2] != '0'){
                num += s[i-2];
                num += s[i-1];
                if (string("26") >= num){
                    temp += dp[i-2];
                }
            }
            dp[i] = temp;
        }
        return dp[len];
    }
};