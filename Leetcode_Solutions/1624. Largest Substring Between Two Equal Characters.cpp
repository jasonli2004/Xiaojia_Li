class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        vector<int> start(26,-1);
        int longest = -1;
        for (int i = 0; i < s.length(); i++){
            char c = s[i];
            if (start[c - 'a'] != -1){
                longest = max(i - start[c - 'a'] - 1, longest);
            }
            else{
                start[c - 'a'] = i;
            }
        }
        return longest;   
    }
};