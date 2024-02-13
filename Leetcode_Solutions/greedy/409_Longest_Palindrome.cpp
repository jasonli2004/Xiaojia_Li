class Solution {
public:
    int longestPalindrome(string s) {
        int len = 0;
        unordered_map<char, int> map;
        bool odd = false;
        for (char c : s){
            map[c]++;
        }
        int pos = 0;
        for (auto i : map){
            if (!odd && i.second % 2 != 0){
                odd = true;
            }
            len += (i.second/2)*2;
        }
        if (odd){
            return len+1;
        }
        return len;
    }
};
