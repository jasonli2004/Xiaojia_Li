class Solution {
public:
    bool valid_split(string num){
        if (num.length() == 0 || num.length() > 3){
            return false;
        }
        if (num[0] == '0' && num.length() != 1){
            return false;
        }
        if (num.length() == 3){
            if ( stoi(num) > 255){
            return false;
            }
        }
        return true;
    }

    void restore_helper(string& s, vector<string>&ans, int n, int pos){
        if (pos >= s.length()){
            return;
        }
        if (n == 1){
            int x = pos+2;
            int y = s.length()-2;
            int temp = min(x,y);
            for(int i = pos; i <= temp;i++){
                if (valid_split(s.substr(pos, i-pos+1)) && valid_split(s.substr(i+1,s.length()-(i+1)))){
                    s.insert(i+1,".");
                    ans.push_back(s);
                    s.erase(i+1,1);
                }
            }
        }
        else{
            int x = pos+2;
            int y = s.length()-2;
            int temp = min(x,y);
            for(int i = pos; i <= temp;i++){
                if (valid_split(s.substr(pos, i-pos+1))){
                    s.insert(i+1,".");
                    restore_helper(s, ans, n-1, i+2);
                    s.erase(i+1,1);
                }
            }
        }
        return;
    }

    vector<string> restoreIpAddresses(string s) {
        vector<string> ans;
        restore_helper(s, ans, 3, 0);
        return ans;
    }

};