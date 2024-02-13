class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int i = 0;
        int j = 0;
        int m = g.size();
        int n = s.size();
        while (i <  m && j < n){
            if (g[i] <= s[j]){
                i++;
                j++;
            }
            else{
                j++;
            }

        }
        return i;
    }
};