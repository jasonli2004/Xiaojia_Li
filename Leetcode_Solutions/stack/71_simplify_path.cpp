class Solution {
public:
    string simplifyPath(string path) {
        string ans = "";
        string temp;
        int pos = -1;
        stack<string> stk;
        for (int i = 0; i < path.size(); i++){
            if (path[i] == '/' || i == path.size()-1){
                if (i == path.size()-1 && path[i] != '/'){
                    temp = path.substr(pos+1, i - pos);
                }
                else{
                    temp = path.substr(pos+1, i - pos - 1);
                }
                if (temp == "." || temp ==""){
            
                }
                else if (temp == ".."){
                    if (!stk.empty()){
                        stk.pop();
                    }
                }
                else{
                    stk.push(temp);
                }
                pos = i;
            }
        }
        while (!stk.empty()){
            ans = "/" + stk.top() + ans;
            stk.pop();
        }
        if (ans == ""){
            ans = "/";
        }
        return ans;
    }
};