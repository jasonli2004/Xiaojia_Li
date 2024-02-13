class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> ans;
        unordered_map<string, int> map;
        if (s.length() < 10){
            return {};
        }
        for (int i = 0; i <= s.length() - 10; i++){
            string temp = s.substr(i, 10);
            map[temp]++;
        }
        for (auto itr : map){
            if (itr.second >= 2){
                ans.push_back(itr.first);
            }
        }
        return ans;
    }
};