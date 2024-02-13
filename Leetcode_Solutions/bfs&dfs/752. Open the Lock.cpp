class Solution {
public:
    string move(string temp, int i, int j){
        temp[i] = ((temp[i] - '0' + j + 10) % 10) + '0';
        return temp;
    }


    int openLock(vector<string>& deadends, string target) {
        vector<int> movement = {-1, 1};
        unordered_set<string> visited;
        string s = "0000";
        for (int i = 0; i < deadends.size(); i++){
            visited.insert(deadends[i]);
        }
        queue<int> cnt;
        queue<string> q;
        if (visited.find(s) != visited.end()){
            return -1;
        }
        cnt.push(0);
        q.push(s);
        visited.insert(s);
        while (!q.empty()){
            string temp = q.front();
            int cur_cnt = cnt.front();
            if (temp == target){
                return cur_cnt;
            }
            for (int i = 0; i < 4; i++){
                for (int j : movement){
                    string after = move(temp,i,j);
                    if (visited.find(after) == visited.end()){
                        q.push(after);
                        cnt.push(cur_cnt+1);
                        visited.insert(after);
                    }
                }
            }
            q.pop();
            cnt.pop();
        }     
        return -1;   
    }
};