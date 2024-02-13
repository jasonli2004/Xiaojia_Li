//version1
class Solution {
public:
    int numDecodings(string s) {
        char zero = '0';
        int len = s.length();
        vector<int> dp(len,0);
        if (s[0] == '0'){
            return 0;
        }
        dp[0] = 1;
        if (len >= 2){
            int num = (int) s[1] - (int) zero;
            int prev_num = (int) s[0] - (int) zero;
            if (num == 0){
                if (prev_num != 1 && prev_num != 2){
                    return 0;
                }
                dp[1] = 1;
            }
            else if (num+prev_num*10 <= 26 && prev_num != 0){
                dp[1] = 2;
            }
            else{
                dp[1] = 1;
            }
        }
        for (int i = 2; i < len; i++){
            int num = (int) s[i] - (int) zero;
            int prev_num = (int) s[i-1] - (int) zero;
            if (num == 0){
                if (prev_num != 1 && prev_num != 2){
                    return 0;
                }
                dp[i] = dp[i-2];
            }
            else if (num+prev_num*10 <= 26 && prev_num != 0){
                dp[i] = dp[i-1]+dp[i-2];
            }
            else{
                dp[i] = dp[i-1];
            }
        }
        return dp[len - 1];
    }
};


//version2 (better memory)
class Solution {
public:
    int numDecodings(string s) {
        char zero = '0';
        int len = s.length();
        int prev_two = 1;
        int prev_one = 0;
        int temp = 1;
        if (s[0] == '0'){
            return 0;
        }
        prev_one = 1;
        for (int i = 1; i < len; i++){
            int num = (int) s[i] - (int) zero;
            int prev_num = (int) s[i-1] - (int) zero;
            if (num == 0){
                if (prev_num != 1 && prev_num != 2){
                    return 0;
                }
                temp = prev_two;
                prev_two = prev_one;
                prev_one = temp;
            }
            else if (num+prev_num*10 <= 26 && prev_num != 0){
                temp = prev_two + prev_one;
                prev_two = prev_one;
                prev_one = temp;
            }
            else{
                temp = prev_one;
                prev_two = prev_one;
                prev_one = temp;
            }
        }
        return temp;
    }
};