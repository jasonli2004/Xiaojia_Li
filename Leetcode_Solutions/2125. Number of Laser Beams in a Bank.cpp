class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int sum = 0;
        int prev = 0;
        for (string row : bank){
            int cnt = count(row.begin(), row.end(), '1');
            sum += prev * cnt;
            if (cnt != 0){
                prev = cnt;
            }
        }
        return sum;
    }
};