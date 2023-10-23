class Solution {
public:
    int romanToInt(string s) {
        int len = s.length();
        int curr = 0;
        int result = 0;
        while (curr<len){
            switch(s[curr]) {
            case 'I':
                result = result + 1;
                s[0] = 'I';
                break;
            case 'V':
                if (s[0] == 'I'){
                    result = result + 3;
                }
                else{
                    result = result + 5;
                }
                s[0] = 'V';
                break;
            case 'X':
                if (s[0] == 'I'){
                    result = result + 8;
                }
                else{
                    result = result + 10;
                }
                s[0] = 'X';
                break;
            case 'L':
                if (s[0] == 'X'){
                    result = result + 30;
                }
                else{
                    result = result + 50;
                }
                s[0] = 'L';
                break;
            case 'C':
                if (s[0] == 'X'){
                    result = result + 80;
                }
                else{
                    result = result + 100;
                }
                s[0] = 'C';
                break;
            case 'D':
                if (s[0] == 'C'){
                    result = result + 300;
                }
                else{
                    result = result + 500;
                }
                s[0] = 'D';
                break;
            case 'M':
                if (s[0] == 'C'){
                    result = result + 800;
                }
                else{
                    result = result + 1000;
                }
                s[0] = 'M';
                break;
            
            default:
                break;
            }
            curr++;
        }
        return result;
    }
};