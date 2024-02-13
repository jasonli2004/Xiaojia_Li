class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        vector<int> pos(primes.size(),0);
        vector<long long> dp(n, 0);
        dp[0] = 1;
        long long temp = 0;
        for (int i = 1; i < n; i++){
            long  long cur_min = INT_MAX;
            int min_pos = 0;
            for (int j = 0; j < primes.size(); j++){
                temp = primes[j] * dp[pos[j]];
                while (temp <= dp[i - 1]){
                    pos[j]++;
                    temp = primes[j] * dp[pos[j]];
                }
                if (cur_min > temp){
                    cur_min = temp;
                    min_pos = j;
                }
            }
            dp[i] = cur_min;
            pos[min_pos]++;
        }
        return dp[n-1];
    }
};