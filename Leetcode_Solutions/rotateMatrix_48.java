class Solution {
    public void rotate(int[][] matrix) {
        int len = matrix.length;
        int cnt = len;
        for (int i = 0; i < len/2; i++){
            for (int j = 0; j < cnt-1; j++){
                matrix = shellRotate(i, cnt, matrix);
            }
            cnt = cnt - 2;
        }

    }
    private int[][] shellRotate(int n, int len, int[][] matrix){
        int x = n;
        int y = n;
        int prev = matrix[x][y];
        int nxt;
        for (int i = 0; i < len - 1; i++){
            nxt = matrix[x][y+1];
            matrix[x][y+1] = prev;
            prev = nxt;
            y = y + 1;
        }
        for (int i = 0; i < len - 1; i++){
            nxt = matrix[x+1][y];
            matrix[x+1][y] = prev;
            prev = nxt;
            x = x + 1;
        }
        for (int i = 0; i < len - 1; i++){
            nxt = matrix[x][y-1];
            matrix[x][y-1] = prev;
            prev = nxt;
            y = y - 1;
        }
        for (int i = 0; i < len - 1; i++){
            nxt = matrix[x-1][y];
            matrix[x-1][y] = prev;
            prev = nxt;
            x = x - 1;
        }
        return matrix;
    }
}