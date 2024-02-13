class Solution {
public:
    bool halvesAreAlike(string s) {
        int n = s.length();
        int cnt = 0;
        for (int i = 0; i < n/2; i++){
            char c = s[i];
            if (c == 'a' || c == 'e' || c == 'o' || c== 'i' || c== 'u' || c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U'){
                cnt++;
            }
        }
        for (int i = n/2; i < n; i++){
            char c = s[i];
            if (c == 'a' || c == 'e' || c == 'o' || c== 'i' || c== 'u' || c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U'){
                cnt--;
            }
        }
        return cnt == 0;
    }
};