class Solution {
public:
    string removeDuplicateLetters(string s) {
        string ans;
        int last_seen[26];
        char c;
        bool visited[26];
        memset(visited,false, sizeof(visited));
        stack<char> stk;
        for (int i = 0; i < s.length(); i++){
            last_seen[(int)s[i] - 97] = i;
        }
        for (int i = 0; i < s.length(); i++){
            c  = s[i];
            if (!visited[(int)c - 97]){
                while (!stk.empty() && stk.top() > c && last_seen[(int)stk.top()-97] > i){
                    visited[(int)stk.top()-97] = false;
                    stk.pop();
                }
                visited[(int)c - 97] = true;
                stk.push(c);
            }
        }
        while (!stk.empty()){
            ans = stk.top() + ans;
            stk.pop();
        }
        return ans;
    }
};