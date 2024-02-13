class Solution {
public:
    int compress(vector<char>& chars) {
        int ptr = 0;
        char prev_char = chars[0];
        int cur_cnt = 0;
        for (char c : chars){
            if (c != prev_char){
                chars[ptr] = prev_char;
                ptr++;
                prev_char = c;
                if (cur_cnt != 1){
                string s = to_string(cur_cnt);
                    for (char digit : s){
                        chars[ptr] = digit;
                        ptr++;
                    }
                }
                cur_cnt = 1;
            }
            else{
                cur_cnt++;
            }
        }
        chars[ptr] = prev_char;
        ptr++;
        if (cur_cnt != 1){
            string s = to_string(cur_cnt);
            for (char digit : s){
                chars[ptr] = digit;
                ptr++;
            }
        }
        cur_cnt = 1;
        return ptr;
    }
};