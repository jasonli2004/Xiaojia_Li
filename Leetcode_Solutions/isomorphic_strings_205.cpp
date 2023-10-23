class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> map;
        unordered_map<char, char> map2;
        int lens = s.length();
        int lent = t.length();
        if (lens != lent){
            return false;
        }
        for (int i = 0; i < lens; i++){
            if (map.find(s[i]) == map.end() && map2.find(t[i]) == map2.end()){
                map[s[i]] = t[i];
                map2[t[i]] = s[i];
            }
            else{
                if (map[s[i]] != t[i] || map2[t[i]] != s[i]){
                    return false;
                }
            }
        }    
        return true;   
    }
};