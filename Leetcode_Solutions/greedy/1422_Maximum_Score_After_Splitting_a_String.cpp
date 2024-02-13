class Solution {
public:
    int maxScore(string s) {
        int len = s.length();
        int temp = 0;
        if (len == 2){
            if (s[0] == '0'){
                temp++;
            }
            if (s[1] == '1'){
                temp++;
            }
            return temp;
        }
        vector<int> zero(len, 0);
        vector<int> one(len, 0);
        for (int i = 0; i < len; i++){
            if (s[i] == '0'){
                temp++;
            }
            zero[i] = temp;
        }
        temp = 0;
        for (int i = len - 1; i >= 0; i--){
            if (s[i] == '1'){
                temp++;
            }
            one[i] = temp;
        }
        temp = 0;
        for (int i = 1; i < len - 1; i++){
            if (temp < zero[i] + one[i]){
                
                temp = zero[i] + one[i];
            }
        }
        return temp;
    }
};