class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int l = 0;
        int r = matrix.size();
        while (l < r){
            int mid = l + (r - l)/2;
            if (matrix[mid][0] == target){
                return true;
            }
            else if (matrix[mid][0] < target){
                l = mid + 1;
            }
            else{
                r = mid;
            }
        }
        int temp = l - 1;
        if (l - 1 < 0){
            return false;
        }
        l = 0;
        r = matrix[0].size();
        while (l < r){
            int mid = l + (r - l)/2;
            if (matrix[temp][mid] == target){
                return true;
            }
            else if (matrix[temp][mid] < target){
                l = mid + 1;
            }
            else{
                r = mid;
            }
        }
        return false;
    }
};

//version 2

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int l = 0;
        int m = matrix.size();
        int n = matrix[0].size();
        int r = m * n;
        while (l < r){
            int mid = l + (r - l) / 2;
            int row = mid / n;
            int col = mid % n;
            if (matrix[row][col] == target){
                return true;
            }
            else if (matrix[row][col] < target){
                l = mid + 1;
            }
            else{
                r = mid;
            }
        }
        return false;
    }
};