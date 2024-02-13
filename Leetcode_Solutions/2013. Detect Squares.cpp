class DetectSquares {
    vector<vector<int>> points;
public:
    DetectSquares() {
        points = vector<vector<int>>(1001, vector<int>(1001, 0));
    }
    
    void add(vector<int> point) {
        int x = point[0];
        int y = point[1];
        points[x][y]++;
    }
    
    int count(vector<int> point) {
        int cnt = 0;
        int x0 = point[0];
        int y0 = point[1];
        for (int i = 0; i <= 1000; i++){
            if (i != x0){
                int side_len = abs(x0 - i);
                if (y0 - side_len >= 0){
                    cnt += points[i][y0] * points[x0][y0-side_len] * points[i][y0-side_len];
                }
                if (y0 + side_len <=1000){
                    cnt += points[i][y0] * points[x0][y0+side_len] * points[i][y0+side_len];
                }
            }
        }
        return cnt;
        
    }
};

/**
 * Your DetectSquares object will be instantiated and called as such:
 * DetectSquares* obj = new DetectSquares();
 * obj->add(point);
 * int param_2 = obj->count(point);
 */