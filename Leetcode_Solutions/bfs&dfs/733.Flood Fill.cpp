class Solution {
public:
    void mark(int x, int y, vector<vector<int>>& image , int target, int color){
        if ( x < 0 || x >= image.size() || y < 0 || y >= image[0].size() || image[x][y] != target || image[x][y] == color){
            return;
        }
        image[x][y] = color;
        mark(x+1,y, image, target, color);
        mark(x-1,y, image, target, color);
        mark(x,y+1, image, target, color);
        mark(x,y-1, image, target, color);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        mark(sr, sc, image, image[sr][sc], color);
        return image;
    }
};