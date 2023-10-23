class Solution {
public:
    static bool less(vector<int>& a, vector<int>&b){
        return a[1] < b[1];
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if (intervals.empty()){
            return 0;
        }
        sort(intervals.begin(), intervals.end(), less);
        int end = intervals[0][1];
        int num = intervals.size() - 1;
        for (int i = 1; i < intervals.size(); i++){
            if (intervals[i][0] >= end){
                num--;
                end = intervals[i][1];
            }
        }
        return num;
    }
};