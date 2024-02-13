class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), [](const vector<int>& first, const vector<int>& second){return first[1] < second[1];});
        int cnt = 0;
        long long prev = -2147483649;
        for (auto it : points){
            if (it[0] > prev){
                cnt++;
                prev = it[1];
            }
        }
        return cnt;
    }
};
class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int arrow=1;
        int last = points[0][1];

        sort(points.begin(),points.end());

        for(int i=0;i<points.size();i++){
            if(points[i][0]>last){
                arrow++;
                last = points[i][1];
            }
            else last = min(last, points[i][1]);
        }

        return arrow;
    }
};