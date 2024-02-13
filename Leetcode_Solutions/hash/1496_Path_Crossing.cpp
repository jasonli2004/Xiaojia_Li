class Solution {
public:
    bool isPathCrossing(string path) {
        unordered_map<int, unordered_set<int>> visited;
        unordered_set<int> set;
        int x = 0;
        int y = 0;
        set.insert(y);
        visited[x] = set;
        for (char c : path){
            if (c == 'N'){
                y++;
            }
            else if (c == 'S'){
                y--;
            }
            else if (c == 'E'){
                x++;
            }
            else{
                x--;
            }
            if (visited.find(x) != visited.end()){
                if (visited[x].find(y) != visited[x].end()){
                    return true;
                }
                else{
                    visited[x].insert(y);
                }
            }
            else{
                unordered_set<int> temp;
                temp.insert(y);
                visited[x] = temp;
            }
        }
        return false;
    }
};