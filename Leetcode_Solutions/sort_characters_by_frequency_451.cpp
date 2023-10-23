class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> m;
        vector<pair<int, char>> v;
        string st = "";
        for (int i = 0; i < s.size(); i++){
            m[s[i]]++;
        }
        for (auto elem : m){
            v.push_back(make_pair(elem.second, elem.first));
        }
        sort(v.begin(), v.end(), greater<>());
        for (int i = 0; i < v.size(); i++){
                st += string(v[i].first,v[i].second);
        }
        return st;
    }
};