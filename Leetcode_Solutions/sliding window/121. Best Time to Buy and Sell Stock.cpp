class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int l = prices[0];
        int cur_max = 0;
        for (int num : prices){
            if (num < l){
                l = num; 
            }
            cur_max = max(cur_max,num - l);
        }
        return cur_max;
    }
};