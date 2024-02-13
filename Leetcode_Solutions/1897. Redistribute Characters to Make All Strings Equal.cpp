class Solution {
public:
    bool makeEqual(vector<string>& words) {
        int len = words.size();
        vector<int> word(26, 0);
        for (string s : words){
            for (char c : s){
                word[c - 'a']++;
            }
        }
        for (int i = 0; i <= 25; i++){
            if (word[i] % len != 0){
                return false;
            }
        }
        return true;
    }
};