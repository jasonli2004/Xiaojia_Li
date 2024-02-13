class Solution {
public:
    string expansion(int pos1, int pos2, string& s){
        int l = pos1;
        int r = pos2;
        while (l >= 0 && r < s.length()){
            if (s[l] == s[r]){
                l--;
                r++;
            }
            else{
                break;
            }
        }
        return s.substr(l+1, r - l - 1);
    }

    string longestPalindrome(string s) {
        string ans = "";
        ans = ans + s[0];
        int cur_len = 1;
        for (int i = 0; i < s.length(); i++){
            string temp = expansion(i, i, s);
            if (temp.length() > cur_len){
                ans = temp;
                cur_len = temp.length();
            }
        }
        for (int i = 0; i < s.length()-1; i++){
            string temp = expansion(i, i+1, s);
            if (temp.length() > cur_len){
                ans = temp;
                cur_len = temp.length();
            }
        }
        return ans;
    }
};