class Solution {
public:
    string findLongestWord(string s, vector<string> dictionary) {
        string result = "";
        int diclen = dictionary.size();
        int slen = s.size();
        string temp;
        for (int i = 0; i < diclen; i++){
            string temp = dictionary[i];
            int s_pt = 0;
            int dic_pt = 0;
            int cnt = 0;
            int dic_size = temp.length();
            while (s_pt < slen && dic_pt < dic_size){
                if (s[s_pt++] == temp[dic_pt]){
                    dic_pt++;
                    cnt++;
                }
            }
            if (cnt == dic_size && (dic_size > result.size() || (result.size()==dic_size && result > temp))){
                result = temp;
            }
        }
        return result;
    }
};