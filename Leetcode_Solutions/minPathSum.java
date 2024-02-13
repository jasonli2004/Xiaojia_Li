class Solution {
    public int minPathSum(int[][] grid) {
        int m = grid.length-1;
        int n = grid[0].length-1;
        int[][] memo = new int[m+1][n+1];
        for (int[] i : memo){
            Arrays.fill(i,-1);
        }
        return minpath(0,0, grid, m, n, memo);
    }
    private int minpath(int a, int b, int[][]grid, int m, int n , int[][] memo){
        if (a == m && b == n){
            return grid[m][n];
        }
        if (a > m || b > n){
            return Integer.MAX_VALUE;
        }
        if (memo[a][b] != -1){
            return memo[a][b];
        }
        else{
            memo[a][b] = grid[a][b]+Math.min(minpath(a+1,b,grid,m,n,memo), minpath(a,b+1,grid,m,n,memo));
            return memo[a][b];
        }
    }
}