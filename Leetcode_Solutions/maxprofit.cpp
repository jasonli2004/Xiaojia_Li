class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int temp = 0;
        int maxSell = 0;
        int maxprofit = -1;
        for(int i = 0; i <prices.size()-1; i++){
            int maxSell = *max_element(prices.begin()+i,prices.end());
            temp = maxSell - prices[i];
            if (temp > maxprofit){
                maxprofit = temp;
            }
        }
        if (maxprofit >= 0){
            return maxprofit;
        }
        return 0;
    }
};