class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {
        int upper = max(prices[0], prices[1]);
        int lower = min(prices[0], prices[1]);
        for (int i = 2; i < prices.size(); i++){
            if (prices[i] < upper){
                if (prices[i] <= lower){
                    upper = lower;
                    lower = prices[i];
                }
                else{
                    upper = prices[i];
                }
            }
        }
        int left = money - upper - lower;
        if (left >= 0){
            return left;
        }
        return money;
        
    }
};