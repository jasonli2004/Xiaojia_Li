class Solution {
public:
    int valid_cell(int i, int j, int m, int n){
        if (i < 0 || i >= m || j < 0 || j >= n){
            return false;
        }
        return true;
    }
    int get_avg(int row, int column, vector<vector<int>>& img){
        int m = img.size();
        int n = img[0].size();
        int cnt = 0;
        int sum = 0;
        for (int i = row - 1; i <= row + 1; i++){
            for (int j = column - 1; j <= column + 1; j++){
                if (valid_cell(i,j,m,n)){
                    cnt++;
                    sum += img[i][j];
                }
            }
        }
        return sum/cnt;
    }
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        vector<vector<int>> ans(img.size(), vector<int>(img[0].size(), 0));
        for (int i = 0;  i < img.size(); i++){
            for (int j = 0; j < img[0].size();j++){
                ans[i][j] = get_avg(i, j, img);
            }
        }
        return ans;
    }
};