//knapsack_dumb
class Solution {
public:
    int convertTime(string current, string correct) {
        int diff = (((int) correct[0]*10 + (int) correct[1])*60 + ((int) correct[3]*10 + (int) correct[4])) - (((int) current[0]*10 + (int) current[1])*60 + ((int) current[3]*10 + (int) current[4]));
        vector<int> dp(diff+1, diff+1);
        dp[0] = 0;
        int increment[4] = {1,5,15,60};
        for (int i = 1; i <= 4; i++){
            int temp = increment[i-1];
            for (int j = temp; j <= diff; j++){
                dp[j] = min(dp[j], dp[j-temp]+1);
            }
        }
        return dp[diff];
    }
};

//The math way
class Solution {
public:
    int convertTime(string current, string correct) {
        int diff = (((int) correct[0]*10 + (int) correct[1])*60 + ((int) correct[3]*10 + (int) correct[4])) - (((int) current[0]*10 + (int) current[1])*60 + ((int) current[3]*10 + (int) current[4]));
        int n1 = diff/60;
        diff = diff % 60;
        int n2 = diff/15;
        diff = diff%15;
        int n3 = diff/5;
        diff = diff%5;
        return (diff + n1 + n2 + n3);
    }
};


