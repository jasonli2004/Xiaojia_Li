class Solution {
public:
    bool judgeSquareSum(long c) {
        long l = 0;
        long r = (long) sqrt( (double) c);
        long sum;
        while (l <= r){
            sum = l*l + r*r;
            if (sum == c){
                return true;
            }
            if (sum < c){
                l++;
            }
            else{
                r--;
            }
        }
        return false;
    }
};