class Solution {
public:
        double find_div(string cur, string target, unordered_map<string, unordered_map<string, double>>& mp, unordered_set<string>& visited){
            if (mp.find(cur) == mp.end()){
                return -1.0;
            }
            if (mp[cur].find(target) != mp[cur].end()){
                return mp[cur][target];
            }
            for (auto p : mp[cur]){
                string s = p.first;
                if (visited.find(s) == visited.end()){
                    visited.insert(s);
                    double temp = find_div(s, target, mp, visited);
                    if (temp != -1.0){
                        mp[cur][target] = p.second * temp;
                        return p.second * temp;
                    }
                    visited.erase(s);
                }
            }
            return -1.0;
        }

    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        vector<double> ans;
        unordered_map<string, unordered_map<string, double>> mp;
        for (int i = 0; i < equations.size(); i++){
            string first = equations[i][0];
            string second = equations[i][1];
            mp[first][second] = values[i];
            mp[second][first] = 1.0 / values[i];
        }
        for (int i = 0; i < queries.size(); i++){
            unordered_set<string> visited;
            ans.push_back(find_div(queries[i][0], queries[i][1], mp, visited));
        }
        return ans;
    }
};