class Solution {
public:
    vector<int> diStringMatch(string s) {
        int len = s.length();
        int up = len;
        int down = 0;
        vector<int> ans(len+1, 0);
        for (int i = len-1; i >= 0; i--){
            if (s[i] == 'I'){
                ans[i+1] = up--;
            }
            else{
                ans[i+1] = down++;
            }
        }
        ans[0] = up;
        return ans;
    }
};