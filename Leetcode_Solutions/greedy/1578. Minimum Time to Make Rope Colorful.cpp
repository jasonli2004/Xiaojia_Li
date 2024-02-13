class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        colors += '!';
        neededTime.push_back(0);
        char prev = colors[0];
        char cur;
        int sum = neededTime[0];
        int ans = 0;
        int max_time = neededTime[0];
        for (int i = 1; i < colors.length(); i++){
            cur = colors[i];
            if (cur != prev){
                ans += sum - max_time;
                sum = 0;
                max_time = 0;
            }
            sum += neededTime[i];
            max_time = max(neededTime[i], max_time);
            prev = cur;
        }
        return ans;
    }
};