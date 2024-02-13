class Solution {
public:
    string addStrings(string num1, string num2) {
        int l1 = num1.length();
        int l2 = num2.length();
        string s = "";
        int prev = 0;
        for (int i = 1; i <= min(l1, l2); i++){
            int sum = (num1[l1-i] - '0') + (num2[l2-i] - '0')  + prev;
                prev = sum/10;
                sum = sum % 10;
            s = to_string(sum) + s;
        }
        if (l1 > l2){
            for (int i = 1; i <= l1-l2; i++){
                int sum = (num1[l1-l2-i] - '0')  + prev;
                prev = sum/10;
                sum = sum % 10;
                s = to_string(sum) + s;
            }
        }
        else {
            for (int i = 1; i <= l2-l1; i++){
                int sum = (num2[l2-l1-i] - '0')  + prev;
                prev = sum/10;
                sum = sum % 10;
                s = to_string(sum) + s;
            }
        }
        if (prev == 1){
            s = "1" + s;
        }
        return s;
    }
};