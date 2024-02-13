class Solution {
public:
    static bool cmp(const string &a, const string &b) {
        return a+b > b+a;
    }
    string largestNumber(vector<int>& nums) {
        vector<string> v;
        string ans = "";
        for (int i : nums){
            v.push_back(to_string(i));
        }
        sort(v.begin(),v.end(), cmp);
        bool zero = true;
        for (int i = 0; i < nums.size(); i++){
            ans = ans + v[i];
        }
        if (ans[0] == '0'){
            return "0";
        }
        return ans;
    }
};