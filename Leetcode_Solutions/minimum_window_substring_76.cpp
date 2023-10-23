class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> table;
        for (int i = 0; i < t.size(); i++){
            table[t[i]]++;
        }
        int cnt = 0;
        int l = 0;
        int min_l = 0;
        int min_size = s.size()+1;
        for (int r = 0; r < s.size(); r++){
            if (table.find(s[r]) != table.end()){
                if (--table[s[r]] >= 0){
                    cnt++;
                }
                while(cnt == t.size()){
                    if (r - l + 1 < min_size){
                        min_l = l;
                        min_size = r-l+1; 
                    }
                    if (table.find(s[l]) != table.end() && ++table[s[l]] > 0){
                        cnt--;
                    }
                    ++l;
                }
            }
        }
        if (min_size > s.size()){
            return "";
        }
        return s.substr(min_l,min_size);
    }
};