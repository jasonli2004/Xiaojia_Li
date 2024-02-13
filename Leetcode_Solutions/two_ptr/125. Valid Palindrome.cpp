class Solution {
public:
    bool isAlpha(char c){
        return (('a' <= c && c <= 'z') || ('A' <= c && c <= 'Z') || ('0' <= c && c <= '9'));
    }
    bool isPalindrome(string s) {
        int pt1 = 0;
        int pt2 = s.length() - 1;
        while (pt1 < pt2){
            if (!isAlpha(s[pt1])){
                pt1++;
                continue;
            }
            if (!isAlpha(s[pt2])){
                pt2--;
                continue;
            }
            if (tolower(s[pt1]) != tolower(s[pt2])){
                return false;
            }
            pt1++;
            pt2--;
        }
        return true;
    }
};