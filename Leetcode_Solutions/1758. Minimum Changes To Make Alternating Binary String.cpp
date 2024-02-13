class Solution {
public:
    int minOperations(string s) {
        int cnt = 0;
        for (int i = 0; i < s.length() - 1; i += 2){
            if (s[i] == '1'){
                cnt++;
            }
            if (s[i+1] == '0'){
                cnt++;
            }
        }
        if (s.length()%2 == 1 && s[s.length()-1] == '1'){
            cnt++;
        }
        int temp = s.length() - cnt;
        return min(temp, cnt);
    }
};