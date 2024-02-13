class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n <= 0){
            return false;
        }
        while ((n/2)*2 == n){
            n = n/2;
        }
        return n == 1;
    }
};