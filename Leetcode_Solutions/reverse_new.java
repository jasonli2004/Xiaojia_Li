class Solution {
    public int reverse(int x) {
        int cnt = 0;
        int total = 0;
        int prev = 0;
        boolean positive = true;
        int[] list = new int[11];
        if (x == Integer.MIN_VALUE || x == 0){
            return 0;
        }
        if (x < 0){
            positive = false;
            x =  0 - x;
        }
        while (x > 0){
            list[cnt] = x % 10;
            x = x/10;
            cnt++;
        }
        for (int i = 0; i < 11; i++ ){
            total = total*10 +  list[i];
            if ((prev - list[i])/10 != prev){
                return 0;
            }
            else{
                prev = total;
            }
        }
        if (positive){
            return prev;
        }
        return 0-prev;
    }
}